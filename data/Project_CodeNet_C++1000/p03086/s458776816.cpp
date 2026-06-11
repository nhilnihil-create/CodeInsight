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
    string S;
    cin >> S;
    int res = 0;
    int count = 0;
    for (int i = 0; i < S.length(); ++i) {
        if (S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T') {
            ++count;
            res = max(res, count);
        }
        else {
            count = 0;
        }
    }
    cout << res << endl;
    return 0;
}