				/*****************************************************
 				*	Logged in : HABIBUR RAHMAN						 *
				*	Dept	  : COMPUTER SCIENCE AND ENGINEERING	 *
				*													 *
				*	KHULNA UNIVERSITY OF ENGINEERING AND TECHNOLOGY  *
				******************************************************/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<string> vs;
typedef pair<ll,ll> pll;
#define fast_io 			ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(v) 				v.begin(),v.end()
#define allr(v) 			v.rbegin(),v.rend()
#define rep(i,a,b) 			for(ll i=a;i<=b;i++)
#define rep0(i,n)			for(ll i=0;i<n;i++)
#define rrep0(i, n) 		for(ll i=(ll)(n);i>0;--i)
#define rrep(i, a, b) 		for(ll i=(ll)(a);i>=(ll)(b);--i)
#define pb(z) 				emplace_back(z)
#define ff					first
#define ss 					second
#define caset 				int t;cin>>t;for(int tt=1;tt<=t;tt++)
#define sz(X) 				((ll)(X).size())
#define scan(X) 			scanf("%s", (X))
#define ms(v,val)			memset((v),(val),sizeof((v)))
#define ms0(X) 				memset((X), 0, sizeof((X)))
#define ms1(X) 				memset((X), -1, sizeof((X)))
#define m_p(a,b)            make_pair(a,b)
#define get_pos(c,x) 		(lower_bound(c.begin(),c.end(),x)-c.begin())
#define lcm(a,b)            (a*b)/__gcd(a,b)
#define INF9                1000000010
#define INF18               4000000000000000010
#define bpll(a)             __builtin_popcountll(a)
#define sqr(a)              ((a)*(a))
#define nl					"\n"
//#define mod					1e9+7;
#define mx_el(v)			*max_element(all(v));
#define mn_el(v)			*min_element(all(v));
#define pcase(z,x)    		cout<<"Case "<<z<<": "<<x<<"\n"
const double pi = 2*acos(0) ;
#define display(v)			vi :: iterator it;for(it=(v).begin();it!=(v).end();it++){cout << *it << " " ;}cout << endl;
#define taking(n,v) 		for(ll i=0;i<(n);i++){ll inp;cin>>inp;(v).push_back(inp);}
/*-------------------------some important functions--------------------------------------------------------------------*/
ull binpow(ull b,ull n){if(n==0)return 1;if(n==1)return b;if(n&1) return binpow(b,n-1)*b;else return binpow(b*b,n/2);}
ll bigmod(ll a,ll n,ll mod){if(n==0)return 1;ll res=bigmod(a,n/2,mod);if(n&1){return ((res%mod)*(res%mod)*a)%mod;}else return ((res%mod)*(res%mod))%mod;}
/*--------------------------------------------x----------------------------------------------x--------------------------*/
void start(){
      #ifndef ONLINE_JUDGE 
      freopen("input.txt" , "r" , stdin) ;
      freopen("output.txt" , "w" , stdout) ;
      #endif
}
void solve(){
	ll n;cin>>n;
	ll a[n+1];
	rep0(i,n){
		cin>>a[i];
	}
	ll cnt=a[0];
	rep(i,1,n-1){
		cnt=__gcd(a[i],cnt);
	}
	cout << cnt << nl;
}
 	 
int main() {
	fast_io
	//start();
    //caset{
    	//cout << "Case " << tt << ": ";
		  solve();
	//}
	
	return 0;
}