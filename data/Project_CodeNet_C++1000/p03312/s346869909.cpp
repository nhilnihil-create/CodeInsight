	#include<bits/stdc++.h>
	using namespace std;

	#define TRACE
	 
	#ifdef TRACE
	#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
	    cerr << name << " : " << arg1 << std::endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
	    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
	}
	#else
	#define trace(...)
	#endif

	#define ll   long long
	#define ld long double
	#define all(v) v.begin(),v.end()
	#define pb push_back
	#define S second
	#define F first
	#define die() return 0;


	#define md          1000000007
	#define fmd         998244353 
	#define M           200011
	#define N            18
	ll exp(ll a,ll b){if(b<0)return 0;ll r=1;while(b){if(b&1)r=r*a%md,r%=md;a=a*a%md;b/=2;}return r;}
	ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}

	int solve(){
	    ll n,i,j,k,m,x,y,z;
	    cin>>n;
	    vector<ll> a(n+1),d(n+1);
	    for(i=1;i<=n;++i){
	    	cin>>a[i];d[i]=d[i-1]+a[i];
	    }
	    ll ans=1e18;
		for(i=1;i<=n;++i){
			ll sum=d[i];
			x=0;ll p=i;
			vector<pair<ll,ll> > p1;
			for(;p>=1;p/=2){
				while(x+p<i&&d[x+p]<=sum-d[x+p])x+=p;
			}
			if(x!=0)
				p1.pb({d[x],sum-d[x]});
			if(x+1!=i)
				p1.pb({d[x+1],sum-d[x+1]});
			if(!p1.size())continue;
			vector<pair<ll,ll> > p2;
			x=i;p=n;
			for(;p>=1;p/=2){
				while(x+p<=n&&d[x+p]-d[i]<=d[n]-d[x+p])x+=p;
			}
			if(x!=i)
				p2.pb({d[x]-d[i],d[n]-d[x]});
			if(x+1!=n)
				p2.pb({d[x+1]-d[i],d[n]-d[x+1]});
			if(!p2.size())continue;
			for(auto x1:p1){
				for(auto x2:p2){
					vector<ll> pp;
					// trace(x1.F,x1.S,x2.F,x2.S,i);
					pp.pb(x1.F);pp.pb(x1.S);pp.pb(x2.S);pp.pb(x2.F);

					sort(all(pp));
					ans=min(ans,pp.back()-pp[0]);
				}
			}
		}
			cout<<ans<<"\n";










	    // trace(f(2,2));



		die();

	}
	 
	 
	int main(){
	 
	 
	#ifndef ONLINE_JUDGE
	    double _tBeg=clock();
	#endif

	     
	    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	    int t;
	    t=1;;
	    // prec();
	    // cin>>t;
	 
	    while(t--){

	        solve();
	    }
	 
	 
	 
	 


	#ifndef ONLINE_JUDGE
	    double _tEnd=clock();
	    // printf("\ntotal time %.6f\n",(_tEnd-_tBeg)/CLOCKS_PER_SEC);
	#endif
	 
	    die();
	}
