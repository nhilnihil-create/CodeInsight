#pragma GCC optimize("O4")
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define MOD (ll)(1e9+7)
#define INF (9e18)
#define int ll
#define EPS (1e-6)
#define DB(x) #x<<":"<<x<<" "
using namespace std;
using ll=long long;
using pii=pair<int,int>;

void INIT(){
#ifdef LOCAL_TEST
	freopen("D:\\input.in","r",stdin);
	freopen("D:\\output.out","w",stdout);
	freopen("D:\\error.out","w",stderr);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }
int fpow(int b,int p){
	b%=MOD;
	int ans=1;
	while(p>0){
		if(p&1) ans=(ans*b)%MOD;
		p/=2;
		b=(b*b)%MOD;
	}
	return ans;
}

int32_t main() {
	INIT();
	//code...
	string s; cin>>s;
	int now=0;
	int ans=0;
	For(i,0,sz(s)-1){
		if(s[i]=='W'){
			ans+=i-now;
			now++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
