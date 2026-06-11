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
    ll n;
    cin >> n;

    vector <ll > a;

    a.pb(n);
    ll t;
    
    if(n%2) t=3*n+1;
    else t=n/2;
    ll cnt=1;
    while(find(all(a),t)==a.end())
    {
        a.pb(t);
        if(t%2) t=3*t+1;
        else t=t/2;
        cnt++;

    }
    cout << cnt+1 << endl;
    
    
    //---------------------------------
    
    return 0;
}
