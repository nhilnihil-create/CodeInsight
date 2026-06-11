#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    list<int> b;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        b.push_front(a);
    }

    stack<int> ans;
    while (!b.empty()) {
        bool isok = false;
        int i = 0;
        for (auto itr = b.begin(); itr != b.end(); ++itr) {
            if (*itr == b.size() - i) {
                ans.push(*itr);
                b.erase(itr);
                isok = true;
                break;
            }
            i++;
        }
        if (!isok) {
            cout << -1 << endl;
            return 0;
        }
    }

    while (!ans.empty()) {
        cout << ans.top() << endl;
        ans.pop();
    }
    return 0;
}
