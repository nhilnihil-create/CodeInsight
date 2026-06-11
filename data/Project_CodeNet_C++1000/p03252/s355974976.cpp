#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string S, T;
    cin >> S;
    cin >> T;
    map<char, char> mpS, mpT;
    REP(i, S.size()) {
        if (mpS.count(S[i]) == 0) mpS[S[i]] = T[i];
        else if (mpS[S[i]] != T[i]) {
            cout << "No" << endl;
            return 0;
        }
        if (mpT.count(T[i]) == 0) mpT[T[i]] = S[i];
        else if (mpT[T[i]] != S[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}