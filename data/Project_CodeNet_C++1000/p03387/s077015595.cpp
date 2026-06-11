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
    vector<int> ABC(3);
    cin >> ABC[0] >> ABC[1] >> ABC[2];
    sort(ABC.begin(), ABC.end());
    int A = ABC[0], B = ABC[1], C = ABC[2];
    int res = 0;
    if ((C-B)%2 == 0 && (C-A)%2 == 0) {
        res += (C-B)/2 + (C-A)/2;
    } else if ((C-B)%2 == 0 && (C-A)%2 == 1 || (C-B)%2 == 1 && (C-A)%2 == 0) {
        res += (C-B)/2 + (C-A)/2 + 2;
    } else {
        res += (C-B)/2 + (C-A)/2 + 1;
    }
    cout << res << endl;
    return 0;
}