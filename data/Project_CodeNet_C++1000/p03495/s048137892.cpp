#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int mod = 1e9+7;
const int INF = 1e9;
const int MAX = 1e6;

int main() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    map<int, int> m;
    rep(i, n) {
        cin >> a[i];
        m[a[i]]++;
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (auto x : m) {
        pii p = {x.second, x.first}; // 頻度, 整数
        pq.push(p);
    }
    int cnt = 0;
    while (pq.size() > k) {
        cnt += pq.top().first; // 頻度
        pq.pop();
    }
    cout << cnt << endl;
}