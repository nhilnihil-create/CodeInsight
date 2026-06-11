#include <bits/stdc++.h>
using namespace std;


//defines...
#define ll long long
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define in insert
#define pi 2*acos(0.0)1
#define srt(s) sort(s.begin(),s.end())
#define rsrt(s) sort(s.rbegin(),s.rend())
#define all(x) x.begin(),x.end()
#define mem(a, b) memset(a, b, sizeof(a))

const ll mod=1e9+7;
const ll MX=2e5+5;

//code goes from here...



int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
#endif

    boost
    //---------------------------------
    ll n,m,x;

    cin >> n >> m >> x;
    vector <ll> tx(n);
    for(ll i=0;i<m;i++)
    {
        ll t;
        cin >> t;
        tx[t]++;
    }

    ll c1=0,c2=0;
    for(ll i=x;i<n;i++) c1+=tx[i];
    for(ll i=x;i>=0;i--) c2+=tx[i];

    cout << min(c1,c2) << endl;
    
    //---------------------------------
    
    return 0;
}
