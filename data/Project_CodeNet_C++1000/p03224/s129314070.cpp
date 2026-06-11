#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define dump(val) cerr << __LINE__ << ":\t" << #val << " = " << (val) << endl

using namespace std;

typedef long long int lli;

template<typename T>
vector<T> make_v(size_t a, T b) {
    return vector<T>(a, b);
}

template<typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    lli K = -1;
    if (N == 1) {
        cout << "Yes" << endl;
        cout << "2" << endl;
        cout << "1 1" << endl;
        cout << "1 1" << endl;
        return 0;
    }
    for (lli i = 1; i <= N; i++) {
        if (i * (i - 1) == 2 * N) {
            K = i;
            break;
        } else if (i * (i - 1) > 2 * N) {
            cout << "No" << endl;
            return 0;
        }
    }
    if (K == -1) {
        cout << "No" << endl;
        return 0;
    }
    vector<vector<int>> ans(K);
    int num = 1;
    REP(i, 0, K) {
        REP(j, 0, i) {
            ans[i].push_back(num);
            ans[j].push_back(num);
            num++;
        }
    }
    cout << "Yes" << endl;
    cout << K << endl;
    REP(i, 0, K) {
        cout << ans[i].size();
        for (auto &j : ans[i]) {
            cout << ' ' << j;
        }
        cout << endl;
    }

    return 0;
}
