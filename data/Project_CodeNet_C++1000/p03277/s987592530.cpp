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
 
#define ll   long 
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
class BIT{
public:
    int n;
    vector<ll> B;
    BIT(int sz){
        n=sz;
        B=vector<ll> (n+1);
    }
    void up(int x,int y=1){
        for(;x<=n;x+=x&-x)B[x]+=y;
    }
    ll sum(int x){int s=0;
        for(;x>=1;x-=x&-x)s+=B[x];
        return s;
    }
 
};
vector<ll> v;
ll les(ll po){
	int i,j,k,n=v.size()-1;
	vector<int > d(n+1);
	for(i=1;i<=n;++i){
		if(v[i]>=po)d[i]=1;
		else d[i]=-1;
		d[i]+=d[i-1];
	}
 
	int c=0;
	map<int ,int > h1;
	for(i=0;i<=n;++i)h1[d[i]];
	for(auto x:h1)h1[x.F]=++c;
		BIT b(c);
	ll ans=0;
	b.up(h1[d[0]]);
	for(i=1;i<=n;++i){
		ans+=b.sum(h1[d[i]]);
		b.up(h1[d[i]]);
	}
	return ans;
 
 
}
 
int solve(){
    ll n,i,j,k,m,x,y,z;
    cin>>n;
    v=vector<ll> (n+1);
    ll p=1;
    for(i=1;i<=n;++i){cin>>v[i];p=max(p,v[i]);}
 
    if(n==1){
    	cout<<v[1]<<"\n";die();
    }
    x=0;ll go=(n*(n+1))/2;
// trace(les(20));
	for(;p>=1;p/=2){
		while(x+p<=1e9&&les(x+p)>=go/2)x+=p;
	}
	// trace(les(x));
	cout<<x<<"\n";
 
 
 
 
 
 
 
 
 
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