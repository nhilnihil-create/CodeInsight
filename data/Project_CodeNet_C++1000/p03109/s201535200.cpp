#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)


int main() {
    string S;
    cin >> S;
    int y = 0, m = 0, d = 0;
    y += (S[0] - '0') * 1000;
    y += (S[1] - '0') * 100;
    y += (S[2] - '0') * 10;
    y += (S[3] - '0') * 1;
    m += (S[5] - '0') * 10;
    m += (S[6] - '0') * 1;
    d += (S[8] - '0') * 10;
    d += (S[9] - '0') * 1;

    if (m <= 4) {
        cout << "Heisei" << endl;
        return 0;
    }
    cout << "TBD" << endl;
}
