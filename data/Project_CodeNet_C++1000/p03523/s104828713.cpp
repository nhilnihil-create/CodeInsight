#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<cmath>
#include<iomanip>
#include<set>
#include<string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rrep(i, st, n) for (int i = st; i < n; ++i)
using pii = pair<int, int>;
//const int inf = 1e9 + 7;

int main() {
    string s; cin >> s;
    int table[26] = {0};
    rep(i, s.size()) table[s[i] - 'A']++;
    int flg = 0;
    if (table[10] != 1) flg = 1;
    if (table[7] != 1) flg = 1; //h
    if (table[8] != 1) flg = 1; //i
    if (table[1] != 1) flg = 1; //b
    if (table[17] != 1) flg = 1;
    table[0] = 0; table[1] = 0; table[7] = 0; table[8] = 0; table[10] = 0; table[17] = 0;
    rep(i, 26) if (table[i] != 0) flg = 1;
    if (flg == 0) {
        int cnt = 0; //a
        int cntt = 0;
        int cnttt = 0;
        rep(i, s.size()) {
            if (s[i] == 'A') cnt++;
            if (cnt <= 1 && s[i] == 'K') flg = 1;
            if (flg == 1 && s[i] == 'A') flg = -1;
            if (flg == 1 && s[i] == 'I') flg = 2;
            if (flg == 2 && s[i] == 'A') flg = -1;
            if (flg == 2 && s[i] == 'H') flg = 3;
            if (flg == 3 && s[i] == 'A') cntt++;
            if (cntt <= 1 && flg == 3 && s[i] == 'B') flg = 4;
            if (flg == 4 && s[i] == 'A') cnttt++;
            if (cnttt <= 1 && flg == 4 && s[i] == 'R') flg = 5;
            if (cnt >= 5) flg = -1;
        }
        if (flg == 5) {cout << "YES" << endl; return 0;}
    }
    cout << "NO" << endl;
}
