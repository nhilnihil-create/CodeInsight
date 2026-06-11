#include <bits/stdc++.h>
#define ull unsigned long long
#define endl '\n'
#define ll long long
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define line cout<<"-------------------------"<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mx=300009;
int main()
{
    ll n; 
    cin>>n; 
    ll ans=0; 
    for(ll i=0;i<n;i++)
    {
        ll x; cin>>x; 
        ans=__gcd(ans,x);
    }
    cout<<ans<<endl; 
    
}
