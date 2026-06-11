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
#define all(x) x.begin(),x.end()

const ll mod=1e9+7;
const ll MX=2e5+5;

//code goes from here...



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
#endif

    boost
    //---------------------------------
    ll n,m ,c ; 
    cin >> n >> m >> c; 
    vector <ll> b(m);
    for(auto &i : b) cin >> i;
    int cnt=0;
    while(n--)
    {
        ll ans=0,x;
        for(int i=0;i< m;i++)
        {
            cin >> x; 
            ans+= x*b[i];
        }
        if(ans+c> 0) cnt++;
    }
    cout << cnt << endl;
    //---------------------------------
    
    return 0;
}
