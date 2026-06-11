#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> w(n + 1, 0);
    vector<int> e(n + 1, 0);
    rep(i, n) {
        s[i] == 'W' ? w[i + 1]++ : e[i + 1]++;
        w[i + 1] += w[i];
        e[i + 1] += e[i];
    }
// ---------------------------
    /*rep(i, n + 1) {
        cout << w[i] << ' ';
    }
    cout << endl;
    rep(i, n + 1) {
        cout << e[i] << ' ';
    }
    cout << endl;*/
// 確認済
// ----------------------------
    int mi = 500000;
    int last_e = e[n];
    rep(i, n + 1) {
        mi = min(w[i] + last_e - e[i], mi);
    }
    cout << mi << endl;
}