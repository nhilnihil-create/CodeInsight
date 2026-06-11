#include<bits/stdc++.h>
using namespace std;
#define ff(i,n) for(i=0;i<n;i++)
#define ll long long int
#define pb push_back
#define mp make_pair
ll bg=998244353;
void updateBIT(ll BITree[], ll n, ll index, ll val) 
{ 
    index = index + 1; 
    while (index <= n) 
    { 
        BITree[index] += val; 
        index += index & (-index); 
    } 
} 
ll *constructBITree(ll arr[], ll n) 
{ 
    ll *BITree = new ll[n+1]; 
    for (ll i=1; i<=n; i++) 
        BITree[i] = 0; 
    for (ll i=0; i<n; i++) 
        updateBIT(BITree, n, i, arr[i]); 
    return BITree; 
} 
ll getSum(ll BITree[], ll index)  
{
	ll sum =0;
    index = index + 1; 
    while (index>0) 
    { 
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
void update(ll BITree[], ll l, ll r, ll n, ll val) 
{ 
    updateBIT(BITree, n, l, val); 
    updateBIT(BITree, n, r+1, -val); 
} 
ll gcd(ll n1, ll n2) {
    if (n2 != 0)
        return gcd(n2, n1 % n2);
    else
        return n1;
}
ll pp(string str) 
{ 
    ll l = 0; 
    ll h = str.length() - 1; 
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
            return 0; 
        } 
    } 
	return 1; 
}
int main()
{
    ll t;
    t=1;
    while(t--)
    {
    	ll i,j,n,q,k=0,a=0,ans=bg;
    	string f;
    	cin>>f;
    	n=f.length();
		vector<pair<ll,ll> >vec;
    	if(f[n-1]=='1' || f[0]=='0' || f[n-2] == '0')
		  cout<<"-1";
		else
		{
		    ll l=0,r=n-2;
			while(l<=r)
			{
			     	if(f[l]!=f[r])
			     	{
			     	     cout<<"-1";
						 return 0; 	
					}
					l++;
					r--;
			}
			ll c=0,maxi=-1;
			for(i=0;i<=n/2-1;i++)
			{
			    if(f[i]=='0')
				   c++;
				else
				{
				   if(maxi!=-1)
				    vec.pb(mp(i+1,maxi+1));
				   for(j=1;j<=c;j++)
				   	vec.pb(mp(i+1,i+1-j));
				   maxi = i;	    	
				   c=0; 	
				}   	
			}
			vec.pb(mp(n,maxi+1));
			for(i=n-1;i>maxi+1;i--)
			  vec.pb(mp(n,i));
			ff(i,n-1)
			   cout<<vec[i].first<<" "<<vec[i].second<<endl;  	
		}  			    
    }
    return 0;
}