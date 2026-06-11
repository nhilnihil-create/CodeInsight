#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll K;
    cin >> K;

    deque<ll> que;
    que.push_back(1);

    ll INF = 1e18;
    vector<ll> d(K, INF);
    d[1] = 1;

    // 01BFS
    while (que.size() > 0) {
        auto p = que.front();
        if (p % K == 0) {
            break;
        }
        que.pop_front();

        ll c = d[p];
        if (c < d[(10 * p) % K]) {
            d[(10 * p) % K] = c;
            que.push_front((10 * p) % K);
        }
        c = d[p] + 1;
        if (c < d[(p + 1) % K]) {
            d[(p + 1) % K] = c;
            que.push_back((p + 1) % K);
        }
    }

    put(d[0]);
}
signed main(){ Main();return 0;}