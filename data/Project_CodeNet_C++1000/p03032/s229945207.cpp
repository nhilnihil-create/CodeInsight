#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> V(N);
    deque<int> que;
    rep(i, N) {
        cin >> V[i];
        que.push_back(V[i]);
    }
    ll res = -INF;
    for(int i = 0; i <= K; i++) {
        int lim = K - i;
        for(int j = 0; j <= K; j++) {
            if(i + j > N || i + j > K)
                break;
            deque<int> q = que;
            priority_queue<int, vector<int>, greater<int>> pq;
            rep(ii, i) {
                pq.push(q.front());
                q.pop_front();
            }
            rep(jj, j) {
                pq.push(q.back());
                q.pop_back();
            }
            int rest = K - i - j;
            while(!pq.empty() && pq.top() < 0 && rest > 0) {
                pq.pop();
                rest--;
            }
            ll tmp = 0;
            while(!pq.empty()) {
                tmp += pq.top();
                pq.pop();
            }
            res = max(res, tmp);
        }
    }
    cout << res << endl;
    return 0;
}