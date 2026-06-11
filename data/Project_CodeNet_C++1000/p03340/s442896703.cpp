// Sakhiya07 - Yagnik Sakhiya
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define bp __builtin_popcountll
#define MOD 1000000007
const int N = 2000005;


int main()
{
    ll n;
    cin >> n;
    ll a[n+1],b[n+1][21];
    memset(b,0,sizeof(b));
    for(ll i=1;i<=n;i++)    cin >> a[i];
    for(ll i=20;i>=0;i--)
    {
        for(ll j=1;j<=n;j++)
        {
            if((a[j]&(1<<i)))    b[j][i] = 1;
        }
    }
    for(ll i=0;i<21;i++)
    {
        for(ll j=1;j<=n;j++)   b[j][i] = b[j][i] + b[j-1][i];
    }
    ll ans = 0;
    for(ll i=1;i<=n;i++)
    {
        ll low = 1,high = i;
        ll ans1=-1;
        while(low<=high)
        {
            ll mid = (low + high)/2;
            ll chk = 1;
            for(ll j=0;j<21;j++)
            {
                if(b[i][j] - b[mid-1][j]>1)   chk = 0;
            }
            if(chk)
            {
                high = mid-1;
                ans1 = mid;
            }
            else   low = mid+1;
        }
        ans += (i - ans1 + 1);
    }
    cout<<ans;
}