#include<bits/stdc++.h>
#define MOD 1000000007
#define MOD2 1000000006
#define TEMPMOD1 998244353
#define TEMPMOD2 998244352
#define INF 1000000000000000007
#define NEGINF -1000000000000000007
#define vll vector<ll> 
#define vvll vector<vector<ll>>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define plll pair<ll,pll>
#define vpll vector<pll>
using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll n,k;
    cin>>n>>k;
    ll val=(n+1)/2;
    if(val>=k)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}