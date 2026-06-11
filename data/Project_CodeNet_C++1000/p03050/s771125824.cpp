#include <bits/stdc++.h>
#define INF 1e9
#define INFLL 1ull<<60u
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

set<ll> enum_div(ll n)//nの約数を列挙
{
    set<ll> ret;
    for(ll i=1 ; i*i<=n ; ++i)
    {
        if(n%i == 0)
        {
            ret.insert(i);
            if(i!=1 && i*i!=n)
            {
                ret.insert(n/i);
            }
        }
    }
    // 自分も約数
    ret.insert(n);
    return ret;
}

void solve() {
    ll N; cin >> N;
    auto s = enum_div(N);
    ll ans = 0;
    for(const auto &it :s) {
        auto m = it - 1;
        auto k = N/(m+1);
        if ( m <= k) continue;
        ans += m;
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}