#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    string S, T;
    cin >> S >> T;
    int lenS = S.size(), lenT = T.size();
    int res = -1;
    for (int i = lenS - lenT; i >= 0; i--) {
        bool same = true;
        for (int j = 0; j < lenT; j++) {
            if (S[i+j] != '?' && S[i+j] != T[j]) same = false;
        }
        if (same) {
            res = i;
            break;
        }
    }
    if (res == -1) cout << "UNRESTORABLE" << '\n';
    else {
        for (int i = res; i < res + lenT; i++) S[i] = T[i - res];
        for (char c : S) cout << (c == '?' ? 'a' : c);
        cout << '\n';
    }

}
