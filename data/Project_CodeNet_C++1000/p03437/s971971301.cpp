// Sakhiya07 - Yagnik Sakhiya
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(),x.end()
#define pll pair<ll,ll>
#define mp make_pair
#define bp __builtin_popcountll
#define MOD  998244353
const int N = 200005;
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);srand(time(NULL));

void solve()
{
    ll x,y;
    cin >> x >> y;
    for(ll i=1;i*x<=1e18 && i<=1e6;i++)
    {
        ll temp = i*x;
        if(temp%x==0 && temp%y!=0)  
        {
            cout<<temp;
            return;
        }
    }
    cout<<-1;
}


int main()
{
    FAST;
    ll t = 1;
   // cin >> t;
    while(t--)
    {
        solve();
    }
}