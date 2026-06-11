#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    string bit1, bit2, s;
    int b1=0, b2=0;
    cin >> s;
    rep(i, s.size() / 2) {
        bit1 += "01";
        bit2 += "10";
    }
    if (s.size() % 2 == 1) {
        bit1 += "0";
        bit2 += "1";
    }
    rep(i, s.size()) {
        if (bit1[i] != s[i])b1++;
        if (bit2[i] != s[i])b2++;
    }
    cout << min(b1, b2) << endl;
    return 0;
}