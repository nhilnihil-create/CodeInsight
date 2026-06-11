#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define MOD (ll)(1e9+7)
#define INF (9e18)
#define EPS (1e-6)
#define debug(...) do{\
	cerr<<__PRETTY_FUNCTION__<<" - "<<__LINE__<<\
	" : ("#__VA_ARGS__<<") = ";\
	_OUT(__VA_ARGS__);\
}while(0)
template<typename T>void _OUT(T x){cerr<<x<<endl;}
template<typename T,typename...I>void _OUT(T x,I ...tail){cerr<<x<<", ";_OUT(tail...);}
void INIT(){
	ios::sync_with_stdio(false); cin.tie(0);
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
	string s,t; cin>>s>>t;
	string ans="~";
	string tmp;
	For(i,0,sz(s)-sz(t)){
		tmp=s;
		bool ac=true;
		For(j,i,i+sz(t)-1){
			if(s[j]!='?' && s[j]!=t[j-i]){
				ac=false;
				break;
			}
			tmp[j]=t[j-i];
		}
		if(!ac) continue;
		for(auto &j:tmp) if(j=='?') j='a';
		ans=min(ans,tmp);
	}
	if(ans=="~") cout<<"UNRESTORABLE\n";
	else cout<<ans<<"\n";
	return 0;
}




















