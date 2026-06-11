#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
    string s; cin >> s;
    int rtn = -INF;
    int tmpmax = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
            ++tmpmax;
            rtn = max(rtn, tmpmax);
        } else {
            rtn = max(rtn, tmpmax);
            tmpmax = 0;
        }
    }
    cout << rtn << endl;
}
