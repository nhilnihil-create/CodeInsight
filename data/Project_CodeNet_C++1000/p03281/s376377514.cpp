#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000009;
const long long INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    int res = 0;
    for (int i = 1; i <= N; ++i) {
        if (i % 2 == 0) continue;
        int count = 0;
        for (int j = 1; j <= N; ++j) {
            if (i % j == 0) ++count;
        }
        if (count == 8) ++res;
    } 
    cout << res << endl;
    return 0;
}