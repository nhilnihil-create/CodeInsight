#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    cout << 0 << endl;
    string res;
    cin >> res;
    if (res == "Vacant") return 0;
    int lb = 0, ub = N;
    string prev_res = res;
    int prev_loc = 0;
    REP(i, 20) {
        int m = (lb + ub) / 2;
        cout << m << endl;
        string cur;
        cin >> cur;
        if (cur == "Vacant") break;
        if (prev_loc == lb) {
            if (((m - lb) % 2 == 0) ^ (prev_res == cur)) {
                ub = m;
            } else {
                lb = m;
            }
        } else {
            if (((ub - m) % 2 == 0) ^ (prev_res == cur)) {
                lb = m;
            } else {
                ub = m;
            }
        }
        prev_res = cur;
        prev_loc = m;
    }
}
