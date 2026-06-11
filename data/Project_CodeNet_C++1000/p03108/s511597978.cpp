#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define frw(i, a, b) for(int i = a; i < b; i++)
#define fi first
#define se second
#define pb push_back
#define in insert
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) int(a.size())
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<ll, ll>
#define plll pair<ll, pll>
#define vpii vector<pii>
#define vpiii vector<piii>
#define vpll vector<pll>
#define vplll vector<plll>
#define mo 1000000007
#define mems(a,x) memset(a,x,sizeof(a))
inline ll modpow(ll x,ll n){if(n==0)return 1;if(n==1)return(x%mo);ll u=(modpow(x,n/2));u=(u*u)%mo;if(n%2!=0)u=(u*x%mo)%mo;return u;}
inline ll modinv(ll x){return modpow(x,mo-2);}
inline ll madd(ll a, ll b){if(a>=mo)a=a%mo;if(b>=mo)b=b%mo;if(a+b>=mo)return(a+b)%mo;return(a+b);}
inline ll msub(ll a, ll b){if(a>=mo)a=a%mo;if(b>=mo)b=b%mo;return(((a-b)%mo+mo)%mo);}
inline ll mmul(ll a,ll b){    if(a>=mo)a=a%mo;if(b>=mo)b=b%mo;if(a*b>=mo)return(a*b)%mo;return(a*b);}
inline ll mdiv(ll a,ll bb){if(a>=mo)a=a%mo;ll b=modinv(bb);if(b>=mo)b=b%mo;if(a*b>=mo)return(a*b)%mo;return(a*b);}

ll size[100005];
ll parent[100005];


int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}


int main() 
{ 
	ll n,m;
	cin>>n>>m;
	vector<pair<ll,ll>>v;
	for(int i=1;i<=n;i++)
		make_set(i);
	for(int i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	ll ans=n*(n-1)/2;
	//cout<<ans<<endl;
	ll as[m+1];
	as[m]=ans;
	for(int i=m-1;i>0;i--)
	{
		ll a,b;

		a=v[i].fi;
		b=v[i].se;
		ll p1,p2;
		if(find_set(a)!=find_set(b))
		{
			p1=find_set(a);
			p2=find_set(b);
			p1=size[p1];
			p2=size[p2];
			ll t=p1+p2;
			ans=ans+(p1*(p1-1)/2)+(p2*(p2-1)/2)-(t*(t-1)/2);
			union_sets(a,b);
		}
		as[i]=ans;



	}
	for(int i=1;i<=m;i++)
		cout<<as[i]<<endl;

} 