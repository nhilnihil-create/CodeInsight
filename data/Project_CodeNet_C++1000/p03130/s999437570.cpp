#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int cnts[4];

int main() {
    for (int i = 0, a, b; i < 3; i++) {
        cin >> a >> b;
        a--; b--;
        cnts[a]++;
        cnts[b]++;
    }
    int one_cnt = 0, two_cnt = 0;
    for (int i = 0; i < 4; i++) {
        if (cnts[i] == 2) two_cnt++;
        else if (cnts[i] == 1) one_cnt++;
    }
    if (one_cnt == 2 && two_cnt == 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}