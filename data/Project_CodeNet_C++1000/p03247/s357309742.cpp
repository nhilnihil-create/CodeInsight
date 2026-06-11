#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "../include/debug.hpp"
#else
#define debug(...) 42
#endif

const int MAX = 36;
long long pow2[40];

void init() {
    pow2[0] = 1;
    for (int i=1; i<=MAX; ++i) {
        pow2[i] = pow2[i-1] * 2;
    }
}

string solve(long long X, long long Y, bool odd) {
    string s = "";
    for (int i=MAX; i>=0; --i) {
        long long parm = odd ? pow2[i] : pow2[max(0, i-1)];
        long long ph = odd ? parm-1 : (i == 0 ? 0 : parm);

        if (abs(X+parm) + abs(Y) <= ph) {
            X += parm;
            s = "L" + s;
        } else if (abs(X-parm) + abs(Y) <= ph) {
            X -= parm;
            s = "R" + s;
        } else if (abs(X) + abs(Y+parm) <= ph) {
            Y += parm;
            s = "D" + s;
        } else if (abs(X) + abs(Y-parm) <= ph) {
            Y -= parm;
            s = "U" + s;
        }
    }
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    int N;
    cin >> N;

    vector<int> X(N), Y(N);
    int odd = 0, even = 0;
    for (int i=0; i<N; ++i) {
        cin >> X[i] >> Y[i];
        if (abs(X[i]+Y[i]) % 2 == 0) {
            even ++;
        } else {
            odd ++;
        }
    }
    if (even > 0 && odd > 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << MAX+1 << endl;
    for (int i=0; i<=MAX; ++i) {
        cout << (odd > 0 ? pow2[i] : pow2[max(0, i-1)]) << endl;
    }

    for (int i=0; i<N; ++i) {
        cout << solve(X[i], Y[i], odd > 0) << endl;
    }

    return 0;
}