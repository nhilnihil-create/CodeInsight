#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll ans = 0;
ll lim = 0;
ll N;

void dfs(string target) {
    if (target.size() >= 3) {
        ll num = stol(target);

        map<char, ll> mp;
        rep(i, target.size()) {
            mp[target[i]]++;
        }
        if (mp.size() == 3 && num <= N) {
            // cout << target << " ";
            ans++;
        }
    }

    if (target.size() == lim) {
        return;
    }

    dfs(target + "3");
    dfs(target + "5");
    dfs(target + "7");
}

int main() {
    cin >> N;
    string s = to_string(N);
    lim = s.size();

    string tmp = "";
    dfs(tmp);
    cout << ans << endl;
}