#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, std::vector<long long> a) {
    map<ll, ll> cntmap;
    ll ans = 0;
    rep(i, N) { cntmap[a[i]]++; }
    for (auto i = cntmap.begin(); i != cntmap.end(); i++) {
        if (i->second > i->first) {
            ans += i->second - i->first;
        } else if (i->second < i->first) {
            ans += i->second;
        }
    }
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
