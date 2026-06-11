#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> K(N);
    vector<vector<int>> A(N);
    rep(i, N) {
        cin >> K.at(i);
        rep(j, K.at(i)) {
            int tmp;
            cin >> tmp;
            A.at(i).push_back(tmp);
        }
    }

    vector<int> preferences(M, 0);

    rep(i, N) {
        for(auto a : A.at(i)) {
            preferences[a - 1]++;
        }
    }

    int count = 0;
    rep(i, M) {
        if (preferences.at(i) == N) count++;
    }

    cout << count << endl;

    return 0;
}
