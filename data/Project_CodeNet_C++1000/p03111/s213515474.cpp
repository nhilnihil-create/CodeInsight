#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 10e9;
int N, A, B, C;
vector<int>l(8);

ll dfs(int cur, int a, int b, int c) {
    int ret0, ret1, ret2, ret3;
    if (cur == N) {
        if (min({a, b, c}) > 0) {
            return abs(a-A) + abs(b-B) + abs(c-C)-30;
        } else {
            return INF;
        }
    }
    ret0 = dfs(cur+1, a, b, c);
    ret1 = dfs(cur+1, a+l[cur], b, c) + 10;
    ret2 = dfs(cur+1, a, b+l[cur], c) + 10;
    ret3 = dfs(cur+1, a, b, c+l[cur]) + 10;
    return min({ret0, ret1, ret2, ret3});
}

int main() {
    cin >> N >> A >> B >> C;
    for (int i = 0; i < N; i++) {
        cin >> l[i];
    }
    
    ll ans;
    ans = dfs(0, 0, 0, 0);
    cout << ans << endl;
}
