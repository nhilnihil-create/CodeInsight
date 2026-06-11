#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(j, m) for (int j = 0; j < (int)(m); j++)
#define rep2(i, l, n) for (int i = l; i < (int)(n); i++)


int main() {
    int A,B;
    cin >> A >> B;
    string S;
    cin >> S;
    int count = 0;
    rep(i,A) {
        if (S[i] < '0' || S[i] > '9') {
            count++;
        }
    }
    if (S[A] != '-') {
        count++;
    }
    rep2(j,A + 1, A + B + 1) {
        if (S[j] < '0' || S[j] > '9') {
            count++;
        }
    }
    if (count == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

