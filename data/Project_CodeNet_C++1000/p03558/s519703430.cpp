#include <bits/stdc++.h>
using namespace std;

struct Fast {Fast() {std::cin.tie(0); ios::sync_with_stdio(false);}} fast;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using pll = pair<ll, ll>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

const int INF = 1e9;

int main() {
    int K; cin >> K;
    vi d(K, INF);
    d[1] = 1;

    deque<pii> q;
    q.push_front(pii(1, 1));

    while (!q.empty()) {
        pii val = q.front(); q.pop_front();
        int s, dist; tie(s, dist) = val;

        if (d[(s + 1) % K] > dist + 1) {
            d[(s + 1) % K] = dist + 1;
            q.push_back(pii((s + 1) % K, dist + 1));
        }
        if (d[(10 * s) % K] > dist) {
            d[(10 * s) % K] = dist;
            q.push_front(pii((10 * s) % K,dist));
        }

    }

    cout << d[0] << endl;


}
