#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

ll N;
int cnt = 0;

void dfs(ll cur) {
    if (cur > N) return;

    vector<bool> use(3, false);
    string num = to_string(cur);
    int n = num.size();
    for (int i = 0; i < n; i++) {
        if (num[i] == '3') use[0] = true;
        if (num[i] == '5') use[1] = true;
        if (num[i] == '7') use[2] = true;
    }
    if (use[0] && use[1] && use[2]) cnt++;

    dfs(cur * 10 + 3);
    dfs(cur * 10 + 5);
    dfs(cur * 10 + 7);
}

int main() {
    cin >> N;
    dfs(0);
    cout << cnt << endl;
    return 0;
}