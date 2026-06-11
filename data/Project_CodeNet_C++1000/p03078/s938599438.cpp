#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define mk make_pair
#define fi first
#define se second
#define vll vector<ll>
#define pii pair<ll,ll>
#define vvll vector< vector<ll> >
#define pb push_back
#define sz(v) (v).size()
#define inf 1e18
#define md 1000000007
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define tel(a){cout<<a<<"\n";}
#define tell(a,b){cout<<a<<" | "<<b<<"\n";}
#define telll(a,b,c){cout<<a<<" | "<<b<<" | "<<c<<"\n";}
#define teln(v,n){cout<<"v- ";rep(i,0,n)cout<<v[i]<<" ";cout<<"\n";}
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define tihs if(fopen("inp.txt","r"))freopen("inp.txt", "r", stdin),freopen("out.txt", "w", stdout);
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
 

#define M 1010

ll a[M],b[M],c[M];
ll x,y,z,k;

int main(){
	IOS;
	tihs;
	
	
	cin>>x>>y>>z>>k;
	rep(i,0,x)cin>>a[i];
	rep(i,0,y)cin>>b[i];
	rep(i,0,z)cin>>c[i];
	sort(a,a+x,greater<ll>());
	sort(b,b+y,greater<ll>());
	sort(c,c+z,greater<ll>());
	vll v;
	bool ok=0;
	rep(i,0,x)rep(j,0,y)rep(k1,0,z){
		ll ways=(i+1)*(j+1)*(k1+1);
		if(ways>k){ok=1;break;}
		v.pb(a[i]+b[j]+c[k1]);
	}
	sort(v.rbegin(),v.rend());
	rep(i,0,k)cout<<v[i]<<"\n";	
	return 0;
}