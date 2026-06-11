
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define coutv(v) for (int i = 0; i < (v).size(); ++i) cout << v[i] << ' '; cout << endl;
#define coutvv(v) for (int i = 0; i < (v).size(); ++i) {for (int j = 0; j < (v[i]).size(); ++j) cout << v[i][j] << ' '; cout << endl;}
#define debugv(v) {for (int i = 0; i < (v).size(); ++i) cerr << v[i] << ' '; cerr << endl;}
#define debugvv(v) {for (int i = 0; i < (v).size(); ++i) {for (int j = 0; j < (v[i]).size(); ++j) cerr << v[i][j] << ' '; cerr << endl;}}
#define TC int TESTCASE; cin >> TESTCASE; while (TESTCASE--)
typedef long long ll;



int main() {
    vector<int> a(5);
    cin >> a[0]; cin >> a[1]; cin >> a[2]; cin >> a[3]; cin >> a[4];
    int res = 0;
    int m = 10;
    for (int i = 0; i < 5; i++) {
        if (a[i] % 10 == 0) {
            res += a[i];
        } else {
            res += a[i] + 10 - (a[i] % 10);
            m = min(a[i] % 10, m);
        }

    }
    if (m == 10) {
        cout << res;
    } else {
        cout << res + m - 10;
    }

}
