#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll n, m, ans;
    cin >> n >> m;
    vector<ll> x(m),dist;
    rep(i,m) cin >> x[i];
    sort(all(x));
    if(n>=m) ans = 0;
    else{
        rep(i,m-1) dist.push_back(abs(x[i+1]-x[i]));
        ll sum = accumulate(all(dist), 0LL);
        sort(rall(dist));
        rep(i,n-1) sum -= dist[i];
        ans = sum;
    }
    cout << ans << endl;
    return 0;
}