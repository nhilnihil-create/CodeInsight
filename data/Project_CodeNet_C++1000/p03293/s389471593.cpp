#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    string S,T;
    cin >> S >> T;
    int flag = 0;
    rep(i,S.size()) {
        S.push_back(S[0]);
        S.erase(0,1);
        if (S == T) {
            cout << "Yes" << endl;
            flag++;
            break;
        }
    }
    if (flag == 0) {
        cout << "No" << endl;
    }
}

