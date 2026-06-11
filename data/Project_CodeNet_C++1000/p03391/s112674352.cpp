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
const int MAX=2e5+10;
const ll INF=1e18;


int main(){
	int N;
	cin>>N;
	ll A[MAX], B[MAX];
	bool same=true;
	rep(i,N){
		cin>>A[i]>>B[i];
		if(A[i]!=B[i])same=false;
	}
	if(same){
		cout<<0<<endl;
	}
	else{
		ll ans=0;
		ll dif=INF;
		rep(i,N){
			ans+=A[i];
			if(A[i]>B[i])dif=min(dif, B[i]);
		}
		ans-=dif;
		cout<<ans<<endl;
	}
}