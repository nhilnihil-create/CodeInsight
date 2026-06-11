#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mod 1000000007
#define pb emplace_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double  ld;
#define pii pair<ll,ll> 
#define vi vector< ll > 
#define vvi vector< vi > 
#define vpi vector< pii > 
#define vvpi vector< vpi > 
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define test(t) ll t;cin>>t;while(t--)
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))
#ifndef ONLINE_JUDGE
#define debarr(a,n)cerr<<#a<<":";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<endl;
#define debmat(mat,row,col)cerr<<#mat<<":\n";for(int i=0;i<row;i++){for(int j=0;j<col;j++)cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...)dbs(#__VA_ARGS__,__VA_ARGS__)
template<class S,class T>ostream &operator<<(ostream &os,const pair<S,T> &p){return os<<"("<<p.first<<","<<p.second<<")";}
template<class T>ostream &operator<<(ostream &os,const vector<T> &p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os,const set<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os,const multiset<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class S,class T>ostream &operator<<(ostream &os,const map<S,T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>void dbs(string str,T t){cerr<<str<<":"<<t<<"\n";}
template<class T,class...S>void dbs(string str,T t,S... s){int idx=str.find(',');cerr<<str.substr(0,idx)<<":"<<t<<",";dbs(str.substr(idx+1),s...);}
#else
#define pr(...){}
#define debarr(a,n){}
#define debmat(mat,row,col){}
#endif
ll power(ll x,ll y){ll res = 1;while(y){if(y&1) res = (res*x)%mod;y=y/2,x=(x*x)%mod;}return res%mod;}
ll n,k;
ll func(vpi arr,ll bits)
{
	if(bits==-1)
	{
		ll s = 0;
		for(auto v:arr)
			s+=v.sec;
		return s;
	}
	if(k&(1LL<<bits))
	{
		ll s = 0;
		for(auto v:arr)
		{
			if(!(v.fi&(1LL<<bits)))
				s+=v.sec;
		}
		return max(func(arr,bits-1),s);
	}
	else
	{
		vpi temp;
		for(auto v:arr)
		{
			if(!(v.fi&(1LL<<bits)))
				temp.pb(v);
		}
		return func(temp,bits-1);
	}
}
signed main()
{
    fast;
    cin>>n>>k;
    map < ll , ll > lol;
    fr(i,n)
    {
    	ll a,b;
    	cin>>a>>b;
    	lol[a]+=b;
    }
    vpi arr(lol.size());
    for(auto v:lol)
    	arr.pb(v);
    cout<<func(arr,30);
}
