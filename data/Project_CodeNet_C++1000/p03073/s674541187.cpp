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
    int p1 = 0;
    for (int i = 0; i < S.length(); ++i) {
        if (i % 2 == 0 && S[i] != '0') ++p1;
        if (i % 2 == 1 && S[i] != '1') ++p1;
    }
    int p2 = 0;
    for (int i = 0; i < S.length(); ++i) {
        if (i % 2 == 0 && S[i] == '0') ++p2;
        if (i % 2 == 1 && S[i] == '1') ++p2;
    } 
    cout << min(p1, p2) << endl;
    return 0;
}