#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define fr(i,a,b) for(ll i=a; i<b; i++)
#define rf(i,a,b) for(ll i=a; i>=b; i--)
#define pb push_back
#define mp make_pair
#define show(a) for(auto el:a)cout<<el<<" "
#define ff first
#define ss second
#define pairv vector<pair<ll,ll>>
#define vec vector <ll> 
#define all(a) a.begin(),a.end()
#define fam(v,i) for(auto i=v.begin();i!=v.end();i++)
#define fai(v,i) for(auto i : v)
#define mo 1000000007

#define nn cout<<"\n";
ll pow1(ll n,ll p)
{
if(p==0) return 1;
ll x=pow1(n, p/2);
x=(x*x)%mo;
if(p%2==0)
return x;
else
return (x*n)%mo;
}
bool sortbysec(const pair<ll,ll> &a, 
const pair<ll,ll> &b) 
{ 
return (a.second < b.second); 
} 
bool compare(const pair<ll, ll>&p1, const pair<ll,ll>&p2)
{
if(p1.ff < p2.ff) return true;
if(p1.ff == p2.ff) return p1.ff < p2.ss;
return false;
}
 
ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
ll findlcm(ll arr[], ll n) 
{ 
    ll ans = arr[0]; 
   ll ma=1e+18;
    for (ll i = 1; i < n; i++) 
      {  ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
                if(ans>ma)
                {
                    ans=-1;
                    break;
                }
      }
  
    return ans; 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
     ll n;
     cin>>n;
     ll a=n/3;
     cout<<a;
   
    
     return 0;
}
