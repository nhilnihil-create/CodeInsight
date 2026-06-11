#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int m, k;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> m >> k;
    if (k > (1 << m) - 1) {
        cout << -1;
        return 0;
    } else if (m == k && k == 1) {
        cout << -1;
        return 0;
    }

    if (k == 0) {
        rep(i, 0, (1 << m)) {
            cout << i << ' ' << i << ' ';
        }
    } else {
        set<int> core;
        deque<int> ans;
        rep(i, 0, m + 2) {
            if (k & (1 << i)) {
                core.insert((1 << i));
                ans.push_back((1 << i));
            }
        }

        rep(i, 0, (1 << m)) {
            if (core.find(i) == core.end()) {
                ans.push_front(i);
                ans.push_back(i);
            }
        }

        auto it = core.rbegin();
        while (it != core.rend()) {
            ans.push_back(*it);
            ++it;
        }

        while (!ans.empty()) {
            cout << ans.front() << ' ';
            ans.pop_front();
        }
    }
}
