#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    string S;
    cin >> S;
    int countC = 0;
    int count = 0;
    if (S[0] == 'A' && (S[1] <= 'z' && S[1] >= 'a') && 
    (S[S.size() - 1] <= 'z' && S[S.size() - 1] >= 'a')) {
        for (int i = 2; i < S.size() - 1; i++) {
            if (S[i] == 'C') {
                countC++;
            }
            if (S[i] >= 'a' && S[i] <= 'z') {
                count++;
            }
        }
        if (countC == 1 && count == S.size() - 4) {
            cout << "AC" << endl;
        }
        else {
            cout << "WA" << endl;
        }
    }
    else {
        cout << "WA" << endl;
    }
}

