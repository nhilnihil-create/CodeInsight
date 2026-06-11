#include <bits/stdc++.h>
#define INF 1e9
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
    ll N,M;
    cin >> N >> M;
    // ans d
    // sum(a) >= N, M = d*x, Nd <= M (ちょうじり合わせで他の要素を足す場合があるので、以下になる。)
    // d,d,d,d.... , M-(d*(N-1))
    auto s = enum_div(M);
    ll ans = 1;
    for(const auto &it: s) {
        if(N * it <= M) chmax(ans,it);
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}