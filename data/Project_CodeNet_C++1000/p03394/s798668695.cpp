#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define MOD (ll)(1e9+7)
#define INF 1e17
#define int ll
#define EPS (1e-6)
using namespace std;
using ll=long long;
using pii=pair<int,int>;

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }

int fpow(int b,int p)
{
	if(p==0) return 1;
	int h=fpow(b,p/2);
	if(p%2) return h*b%MOD*h%MOD;
	return h*h%MOD;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin>>n;
	if(n==3){
		cout<<"2 5 63\n";
		return 0;
	}
	vector<int> v={2,4,3,9};
	n-=4;
	for(int i=8;i<=30000 && n>=2;i+=6){
		v.emplace_back(i);
		v.emplace_back(i+2);
		n-=2;
	}
	for(int i=15;i<=30000 && n>=2;i+=12){
		v.emplace_back(i);
		v.emplace_back(i+6);
		n-=2;
	}
	for(int i=6;i<=30000 && n>0;i+=6){
		v.emplace_back(i);
		n--;
	}
	n=sz(v);
	For(i,0,n-1) cout<<v[i]<<" \n"[i==n-1];
	return 0;
}



























