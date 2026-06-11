#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n, m, cnt=0;
    cin >> n >> m;
    vector<ll> a(200000,0);
    rep(i,m){
        ll l, r;
        cin >> l >> r;
        a[--l]++;
        a[r]--;
    }
    rep(i,200000) a[i+1] += a[i];
    rep(i,200000) if(a[i]>=m) cnt++;
    cout << cnt << endl;
    return 0;
}