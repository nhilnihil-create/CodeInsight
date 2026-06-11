// be name khoda
#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
//#define mp make_pair 
typedef long long ll;
#define int long long
#pragma GCC optimize("Ofast")

const int maxn = 2e5+10;
const int mod = 1e9+7;
const ll inf = 1e18+10;
//const int N = 2e6+10;

ll pw(ll a, ll b)
{
    if(b == 0) return 1;
    ll x = pw(a,b/2); x = (x*x) % mod;
    if(b & 1) x = (x*a) % mod;
    return x;
}

int n;
int a[maxn], d[maxn];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n;
    int R = n-(n&1)+1;
    int X = 1;
    for(int i = 1; i <= n-1; i++)
    {
        d[i] = ++X;
        d[R-i] = X;
    }
    d[R] = ++X;

    vector<pair<int,int>> edge;
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++)
            if(d[i] != d[j])
                edge.push_back({i,j});
    
    cout<< edge.size() <<"\n";
    for(auto e : edge)
        cout<< e.F <<" "<< e.S <<"\n";
}
