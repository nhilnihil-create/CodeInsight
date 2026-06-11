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


int main() {
	ll l,q;
	cin>>l>>q;
	string s;
	cin>>s;
	ll j=0,k=0;
	ll o[l+1];
	ll z[l+1];
	ll i=0;
	while(i<l)
	{
		ll n=0;
		
		while(s[i]=='1'&&i<l)
			{
			n++;
			i++;
			}
			o[j]=n;
			
			j++;
			n=0;

			while(s[i]=='0'&&i<l)
			{
				n++;
				i++;
			}
				z[k]=n;
				
				k++;
				n=0;
				
		
	
			

	
	}
	ll sum=0;
	ll
	 ans=0;
	//cout<<o[0]<<endl;
	for(int i=0;i<k;i++)
	{
		if(i<q)
		{
			if(i==0)
				sum+=o[i];
			//cout<<sum<<" ";
			sum+=z[i];
			//cout<<sum<<" ";
			if(i+1<j)
			sum+=o[i+1];
			ans=max(ans,sum);//cout<<sum<<" ";
		}
		else
		{
			sum+=z[i];
			sum-=z[i-q];
			if(i+1<j)
			sum+=o[i+1];
			sum-=o[i-q];
			ans=max(ans,sum);
			//cout<<sum<<" ";
		}
	}
	cout<<ans;


}
