#include<bits/stdc++.h>
#include"unistd.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
signed main(){
	int T;cin>>T;
	while(T--){
		int a,b,c,d;cin>>a>>b>>c>>d;
		if(a<b)puts("No");
		else if(d<b)puts("No");
		else if(c>=b)puts("Yes");
		else {
			int mx=b-gcd(b,d)+a%gcd(b,d);
			if(mx>c%b)puts("No");
			else puts("Yes");
		}
	}
}
