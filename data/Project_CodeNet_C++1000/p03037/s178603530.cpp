#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll INF = 1e18;

int main(void)
{
    ll n, m, l=0, r=INF;
    cin >> n >> m;
    vector<ll> a(200000,0);
    rep(i,m){
        ll a, b;
        cin >> a >> b;
        l = max(l, a);
        r = min(r, b);
    }
    cout << max(0LL, r-l+1) << endl;
    return 0;
}