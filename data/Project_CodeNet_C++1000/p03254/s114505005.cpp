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
    ll n,x;

    cin >> n >> x;

    vector <ll> b(n);
    for(auto &i : b) cin >> i;
    srt(b);

    int cnt=0;

    for(ll i=0;i<n-1;i++)
    {
        if(b[i]<=x)
        {
            x-=b[i];
            cnt++;
        }
    }
    if(b[n-1]==x) cnt++;

    cout << cnt << endl;



    //---------------------------------
    
    return 0;
}
