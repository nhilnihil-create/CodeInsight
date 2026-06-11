#include <bits/stdc++.h>  

using namespace std;

//#define int long long
#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define INF (1 << 30)
#define fi first
#define se second

typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> Pi;
typedef pair<P, P> PP;

const int MOD = 1e9 + 7;
const int dy[]={0, 0, 1, -1};
const int dx[]={1, -1, 0, 0};

template <class T> void chmin(T& a, const T& b) { a = min(a, b); }
template <class T> void chmax(T& a, const T& b) { a = max(a, b); }

int k;
int dist[100000];

int bfs() {
    deque<P> deq;
    deq.push_front(P(1 % k, 1));

    while(!deq.empty()) {
        P p = deq.front(); deq.pop_front();
        if(p.first % k == 0) return p.second;
        if(dist[(p.first * 10) % k] > p.second) {
            dist[(p.first * 10) % k] = p.second;
            deq.push_front(P((p.first * 10) % k, p.second));
        }
        if(dist[(p.first + 1) % k] > p.second + 1) {
            dist[(p.first + 1) % k] = p.second + 1;
            deq.push_back(P((p.first + 1) % k, p.second + 1));
        }
    }
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> k;
    rep(i, k + 1) dist[i] = INF;
    cout << bfs() << endl;
    return 0;
}