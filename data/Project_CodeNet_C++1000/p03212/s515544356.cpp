#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

ll N;
int cnt = 0;

void dfs(ll cur, vector<bool> use) {
    if (cur > N) return;

    if (cur % 10 == 3) use[0] = true;
    if (cur % 10 == 5) use[1] = true;
    if (cur % 10 == 7) use[2] = true;

    if (use[0] && use[1] && use[2]) cnt++;

    dfs(cur * 10 + 3, use);
    dfs(cur * 10 + 5, use);
    dfs(cur * 10 + 7, use);
}

int main() {
    cin >> N;
    vector<bool> use(3, false);
    dfs(0, use);
    cout << cnt << endl;
    return 0;
}