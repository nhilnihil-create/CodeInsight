#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S , T; 
    cin >> S >> T;
    bool ans = false;
    for(int i = 0; i < S.size(); i++) {
        if(S == T) {
            ans = true;
            break;
        }
        S = S.back() + S.substr(0,S.size() - 1);
    }
    if(ans) {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
