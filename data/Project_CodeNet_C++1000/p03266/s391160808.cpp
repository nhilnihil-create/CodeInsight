#include <bits/stdc++.h>
#define REP(i,n)   for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(long long i=(a);((a)<(b)?i<=(b):i>=(b));((a)<(b)?++i:--i))
#define ALL(v)     (v).begin(),(v).end()
#define debug(x)   cerr<<#x<<": "<<(x)<<endl
using namespace std;
using llong = long long;
using vi    = vector<int>;
using vvi   = vector<vi >;
using vvvi  = vector<vvi >;
using pii   = pair<int,int>;
constexpr int    INF=1e9;
constexpr double EPS=1e-9;
constexpr int    MOD=1e9+7;
template<class Type>
void line(const Type &a){int cnt=0;for(const auto &elem:a){cerr<<(cnt++?' ':'>');cerr<<elem;}cerr<<endl;}

int main(){//Refering other editorials.
	int n,k;
	cin>>n>>k;
	
	vector<llong> num(k,0LL);//num[x]:=(1~n間でkで割ってx余る数の個数).
	FOR(i,1,n) num[i%k]++;
	
	llong ans=0LL;
	REP(a,k){
		int b=(k-a)%k;
		int c=(k-a)%k;
		
		if((b+c)%k==0) ans+=num[a]*num[b]*num[c];
	}
	
	cout<<ans<<endl;
}