#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    vector<int> vec = {1, 9, 7, 4};
    rep(i, 4) {
        int N;
        cin >> N;
        rep(i, 4) {
            if (vec[i] == N) {
                vec[i] = -1;
            }
        }
    }
    rep(i, 4) if (vec[i] != -1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}