#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

void solve() {
    int N;
    cin >> N;
    int sum = 0;
    bool ok = false;
    int t = 0;
    for (int i = 1; sum < N; i++) {
        sum += i;
        if (sum == N) {
            ok = true;
            t = i;
            break;
        }
    }
    if (!ok) {
        cout << "No" << endl;
        return;
    }

    vector<vector<int>> ans;
    int now = 0;
    for (int k = 0; k < t + 1; k++) {
        vector<int> a;
        for (int i = 0; i < t - k; i++) {
            a.push_back(now);
            now++;
        }
        ans.push_back(a);
    }


    for (int i = 1; i < t + 1; i++) {
        int d = t - 1;
        int now = i - 1;
        for (int k = 0; k < i; k++) {
            ans[i].push_back(now);
            now += d;
            d--;
        }
        sort(all(ans[i]));
    }
    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].size() << " ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] + 1;
            if (j != ans[i].size()) cout << " ";
        }
        cout << endl;
    }
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}