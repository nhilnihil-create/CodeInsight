#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, s, e) for (int i = (int)(s); i < (int)(e); i++)
#define _rep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define _REP(i, e, s) for (int i = (int)(e - 1); i >= (int)(s); i--)

#define yes cout << "yes" << endl;
#define Yes cout << "Yes" << endl;
#define YES cout << "YES" << endl;

#define no cout << "no" << endl;
#define No cout << "No" << endl;
#define NO cout << "NO" << endl;

#define AC cout << "AC" << endl;
#define WA cout << "WA" << endl;

#define out(s) cout << s << endl;

#define ll long long
#define ull unsigned long long

const unsigned int BIT_FLAG_0 = (1 << 0);  // 0000 0000 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1);  // 0000 0000 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2);  // 0000 0000 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3);  // 0000 0000 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4);  // 0000 0000 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5);  // 0000 0000 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6);  // 0000 0000 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7);  // 0000 0000 1000 0000

const double PI = 3.14159265358979323846;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

unsigned GetDigit(ull num) {
    return log10(num);
}

void nextPernutationPrint(const vector<int>& v) {
    for_each(v.begin(), v.end(), [](int x) { cout << x << " "; });
    cout << endl;
}

int main() {
    int N = 3, ans;
    string A, S = "";
    cin >> A;

    for (int bit = 0; bit < (1 << N); bit++) {
        S = A[0];
        ans = A[0] - '0';
        for (int i = 0; i < N; i++) {
            if (!(bit & (1 << i))) {
                S += '+';
                S += A[i + 1];
                ans += A[i + 1] - '0';
            } else {
                S += '-';
                S += A[i + 1];
                ans -= A[i + 1] - '0';
            }
        }

        if (ans == 7) {
            cout << S << "=7" << endl;
            return 0;
        }
    }
}
