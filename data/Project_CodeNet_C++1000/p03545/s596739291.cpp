#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    string S; cin >> S;
    vi A(4);
    rep(i, S.size()) {
        A[i] = S.at(i) - '0';
    }

    for (int i = 0; i < 1<<3; i++) {
        int ans = A[0];
        string tmp = to_string(A[0]);
        for (int j = 0; j < 3; j++) {
            // +
            if (i & 1<<j) {
                tmp += '+';
                tmp += to_string(A[j + 1]);
                ans += A[j + 1];
            }
            // -
            else {
                tmp += '-';
                tmp += to_string(A[j + 1]);
                ans -= A[j + 1];
            }
        }

        if (ans == 7) {
            cout << tmp << "=7" << endl;
            break;
        }
    }
}
