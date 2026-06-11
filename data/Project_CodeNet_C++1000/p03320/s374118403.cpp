#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int MAX=30010;

ll pt(int e){
	ll ans=1;
	rep(_,e)ans*=10;
	return ans;
}

int main(){
	set<ll> st;
	rep(i,15){
		if(i==0)rep1(k,9)st.insert((ll)k);
		else if(i<=10){
			rep(k,i*10)st.insert( (ll)(k+1)* pt(i)-1);
		}
		else if(i<=14){
			rep(k,(i-1)*10)st.insert( (ll)(k+1)* pt(i)-1);
		}
	}
	int K;
	cin>>K;
	int tmp=K;
	for(auto it=st.begin(); it!=st.end(); it++){
		cout<<*it<<endl;
		tmp--;
		if(tmp==0) break;
	}
}