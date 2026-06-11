#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    vector<int> A = {};
    rep(i, 4) {
        char c;
        cin >> c;
        A.push_back(c - '0');
    }

    for (int i = 0; i < 1<<3; i++) {

        int tmp = A[0];
        string res = to_string(A[0]);
        for (int j = 0; j < 3; j++) {
            // +のパターン
            if (i & 1<<j) {
                tmp += A[j + 1];
                res += "+" + to_string(A[j + 1]);
            }
            // -のパターン
            else {
                tmp -= A[j + 1];
                res += "-" + to_string(A[j + 1]);
            }
        }

//cout << "tmp: " << tmp << ", " << res << endl;
        if (tmp == 7) {
            cout << res << "=7" << endl;
            return 0;
        }
    }
}