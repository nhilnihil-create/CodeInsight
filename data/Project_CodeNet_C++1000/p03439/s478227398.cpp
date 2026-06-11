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
    ll n;
    cin >> n;
    cout<<endl;
    ll val;
    val = 0;
    string last;
    cout<<"0"<<endl;
    cout<<endl;
    cin>>last;
    if(last=="Vacant")   return;
    ll low = 1,high = n-1;
    while(low<=high)
    {
        ll mid = (low + high)/2;
        cout<<mid;
        cout<<endl;
        string now;
        cin >> now;
        cout<<endl;
        if(now=="Vacant")   return;
        ll chk = 0;
        if((mid-val)%2)
        {
            if(now==last) 
            {
                chk = 1;
            }
        }
        else 
        {
            if(now!=last)
            {
                chk = 1;
            }
        }
        if(chk)     high = mid - 1;
        else
        {
            low = mid + 1;
            val = mid;
            last = now;
        }
    }
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