#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int N;
int D[110000], n[110000], d[110000];
unordered_map<int, int> mp;
vint ans;
signed main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {cin >> D[i]; n[i] = 1; mp[D[i]] = i;};
    sort(D + 1, D + N + 1); reverse(D + 1, D + N + 1);
    for (int i = 1; i <= N - 1; i++) {
        int s = mp[D[i]];
        int t = mp[D[i] - N + 2 * n[s]];
        n[t] += n[s];
        d[t] += d[s] + n[s];
        ans.push_back(s); ans.push_back(t);
    }
    if (n[mp[D[N]]] != N || d[mp[D[N]]] != D[N]) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < 2 * (N - 1); i += 2) {
        cout << ans[i] << " " << ans[i + 1] << endl;
    }

}
