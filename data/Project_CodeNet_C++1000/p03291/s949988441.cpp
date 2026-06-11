#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define gadd(x,y) x=add(x,y)
#define gmul(x,y) x=mul(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int MOD = 1e9 + 7;

inline int add(int x, int y){
	int res = x + y;	
	while(res >= MOD)res-=MOD;
	return res;
}

inline int mul(int x,int y){
	return (1LL * x * y) % MOD;
}

int modpow(int x,int p){
	int res = 1;
	while(p){
		if(p&1)gmul(res,x);
		gmul(x,x);
		p/=2;
	}
	return res;
}

inline int invert(int x){
	return modpow(x,MOD - 2);
}

const int N = 1e5 + 5;

int dp[N][4];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int n = s.length();
	int cnt = 1;
	vector<int> a(n);
	rep(i,0,n){
		if(i)a[i] = a[i-1];
		if(s[i] == 'A'){
			gadd(a[i],cnt);
		}
		if(s[i] == '?'){
			gmul(a[i],3);	
			gadd(a[i],cnt);
			gmul(cnt,3);
		}
	}
	vector<int> c(n+1,0);
	cnt = 1;
	for(int i = n-1;i>=0;--i){
		if(i < n-1)c[i] = c[i+1];
		if(s[i] == 'C'){
			gadd(c[i],cnt);
		}
		if(s[i] == '?'){
			gmul(c[i],3);	
			gadd(c[i],cnt);
			gmul(cnt,3);
		}
	}
	int ans = 0;
	rep(i,1,n-1){
		if(s[i] == 'B' || s[i] == '?'){
			gadd(ans, mul(a[i-1],c[i+1]));
		}
	}
	cout << ans << '\n';
}
