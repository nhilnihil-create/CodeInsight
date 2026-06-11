#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    string S; cin >> S;
    string T; cin >> T;
    int s = S.size();
    int t = T.size();
    if(s < t){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    for (int i = s-1; i >= t-1; i--){
        bool ch = true;
        for (int j = 0; j < t; j++){
            if(S[i-j] == T[t-1-j] || S[i-j] == '?'){
                continue;
            } else {
                ch = false;
                break;
            }
        }
        if(ch){
            for (int j = 0; j < t; j++){
                S[i-j] = T[t-1-j];
            }
            break;
        }
        if(i == t-1){
            cout << "UNRESTORABLE" << endl;
            return 0;
        }
    }

    for (int i = 0; i < s; i++){
        if(S[i] == '?'){
            S[i] = 'a';
        }
    }

    cout << S << endl;

    return 0;
}