#include <bits/stdc++.h>
#define rep(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define repr(i, n, m) for (int i = (int)(n) - 1; i >= (int)(m); i--)
#define reply cin >> (s); if (((string)s) == "Vacant") return 0
using namespace std;
using ll = int64_t;
const int MOD = 1000000007; // 10^9+7
// https://atcoder.jp/contests/apc001/tasks/apc001_c

vector<int> seats;

void setSeat(int n, string s) {
    if (s == "Male") seats[n] = 1;
    else seats[n] = 2;
}

int main() {
    int n; cin >> n;
    string s;

    // 0: Unknown
    // 1: Male
    // 2: Female
    seats = vector<int>(n, 0);

    vector<int> initList = {0, n - 1, n / 2};
    for (auto &&i : initList)
    {
        cout << i << endl;
        reply;
        setSeat(i, s);
    }

    int lidx, ridx;
    if ((n / 2 + 1) % 2 == 0) {
        // 要素数が偶数
        if (seats[0] == seats[n / 2]) { // 同性ペア
            lidx = 0;
            ridx = n / 2;
        } else {
            lidx = n / 2;
            ridx = n - 1;
        }
    } else {
        // 要素数が奇数
        if (seats[0] != seats[n / 2]) { // 異性ペア
            lidx = 0;
            ridx = n / 2;
        } else {
            lidx = n / 2;
            ridx = n - 1;
        }
    }

    for (int cnt = 17; cnt > 0; cnt--)
    {
        int mid = (lidx + ridx) / 2;
        cout << mid << endl;
        reply;
        setSeat(mid, s);

        int lnum = mid - lidx + 1;
        int rnum = ridx - mid + 1;
        if (seats[lidx] == seats[ridx]) {
            // 同性ペアの区間＝偶数個の区間
            if (seats[lidx] == seats[mid]) {
                if (lnum % 2 == 0) ridx = mid;
                else lidx = mid;
            } else {
                if (lnum % 2 == 1) ridx = mid;
                else lidx = mid;
            }
        } else {
            // 異性ペアの区間＝奇数個の区間
            if (((ridx - lidx) / 2) % 2 == 0) {
                if (seats[lidx] != seats[mid]) ridx = mid;
                else lidx = mid;
            } else {
                if (seats[lidx] == seats[mid]) ridx = mid;
                else lidx = mid;
            }
        }
    }
}
