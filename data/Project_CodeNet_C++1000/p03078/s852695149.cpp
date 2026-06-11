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



int main() 
{ 
	ll x,y,z,k;
	cin>>x>>y>>z>>k;
	ll a[x],b[y],c[z];
	vector<ll>v;
	priority_queue<ll>p2;
	for(int i=0;i<x;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<y;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<z;i++)
	{
		cin>>c[i];
		
	}
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			{
				v.push_back(a[i]+b[j]);
			}

	ll le=v.size();
	ll s=le;
	le=min(le,k);
	sort(v.begin(),v.end());
	// for(int i=0;i<le;i++)
	// 	cout<<v[s-i-1]<<" ";
	for(int i=0;i<le;i++)
	{
		for(int j=0;j<z;j++)
		{
			ll t=v[s-i-1]+c[j];
			p2.push(t);
		}
	}
	// vector<ll>v;
	// for(int i=0;i<x;i++)
	// {
	// 	for(int j=0;j<y;j++)
	// 	{
	// 		ll temp=a[i]+b[j];
	// 		v.push_back(temp);
	// 	}
	// }
	// sort(v.begin(),v.end(),greater<int>());
	// ll le=v.size();
	// le=min(k,le);
	// cout<<le<<endl;
	// for(int i=0;i<le;i++)
	// {
	// 	for(int j=0;j<z;j++)
	// 	{
	// 		p2.push(v[i]+c[j]);
			
	// 	}
	// }
	while(k--)
	{
		cout<<p2.top()<<endl;
		p2.pop();
	}


} 