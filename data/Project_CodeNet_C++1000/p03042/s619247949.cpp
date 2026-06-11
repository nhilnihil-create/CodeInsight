#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

typedef long long Int;

bool monthOK(int n) {
    if (n >= 1 && n <= 12) return true;
    else return false;
}

int main() {
    string S;
    cin >> S;

    int n, m;
    n = (S[0] - '0') * 10 + (S[1] - '0');
    m = (S[2] - '0') * 10 + (S[3] - '0');

    if (monthOK(n)) {
        if (monthOK(m)) cout << "AMBIGUOUS" << endl;
        else cout << "MMYY" << endl;
    }
    else {
        if (monthOK(m)) cout << "YYMM" << endl;
        else cout << "NA" << endl;
    }
}
