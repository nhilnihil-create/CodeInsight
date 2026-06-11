#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

const int N_MAX = 10010;
vector<vector<int>> tree(N_MAX);
vector<int> res(N_MAX);
queue<int> q;
priority_queue<int> pq;

int main() {
    int n;
    cin >> n;
    rp(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree.at(a).emplace_back(b);
        tree.at(b).emplace_back(a);
    }
    int ans = 0;
    rp(i, 0, n) {
        int c; cin >> c;
        pq.push(c);
        ans += c;
    }
    ans -= pq.top();

    q.push(0);
    while(!q.empty()) {
        int now = q.front(); q.pop();
        res.at(now) = pq.top(); pq.pop();
        for(auto x: tree.at(now)) {
            if(res.at(x) == 0) q.push(x);
        }
    }
    printf("%d\n", ans);
    rp(i, 0, n) {
        printf("%d ", res.at(i));
    }
    printf("\n");
    return 0;

}