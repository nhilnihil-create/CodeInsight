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
    string s;
    cin >> s;
    int count = 0;
    if (s[0] == 'o') ++count;
    if (s[1] == 'o') ++count;
    if (s[2] == 'o') ++count;
    cout << 700 + count * 100 << endl;

    return 0;
}