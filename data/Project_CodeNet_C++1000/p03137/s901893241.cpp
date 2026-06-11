#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int n, m;
    cin >> n >> m;
    if (n >= m) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> x(m);
    rep(i,m) cin >> x[i];
    sort(x.begin(), x.end());
    priority_queue<int> q;
    rep(i,m-1) {
        int a = x[i+1] - x[i];
        q.push(a);
    }
    rep(i,n-1) {
        q.pop();
    }
    int ans = 0;
    while (!q.empty()) {
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}