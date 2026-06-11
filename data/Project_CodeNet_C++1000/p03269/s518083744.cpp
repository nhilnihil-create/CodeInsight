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
typedef pair<int, int> P;
typedef pair<P, int> PP;
//const int MAX=;
//const long double INF=;


int main(){
	int L;
	cin>>L;
	vi v;
	int tmp=L;
	while(tmp>0){
		v.push_back(tmp);
		tmp/=2;
	}
	reverse(v.begin(), v.end());
	int N=sz(v);
	vector<PP> ans;
	rep1(i,N-1){
		PP pp1=make_pair(make_pair(i,i+1), 0);
		ans.push_back(pp1);
		PP pp2=make_pair(make_pair(i,i+1), v[i-1]);
		ans.push_back(pp2);
		if(v[i-1]*2!=v[i]){
			PP pp3=make_pair(make_pair(1,i+1), v[i]-1);
			ans.push_back(pp3);
		}
	}
	int M=sz(ans);
	cout<<N<<" "<<M<<endl;
	rep(i,M){
		PP pp=ans[i];
		P p=pp.first;
		cout<<p.first<<" "<<p.second<<" "<<pp.second<<endl;
	}
}