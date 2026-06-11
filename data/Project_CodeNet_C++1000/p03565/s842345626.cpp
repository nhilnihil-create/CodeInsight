#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main(){
    string S, T;
    cin >> S >> T;
    int ns = S.size();
    int nt = T.size();
    vector<string> V;
    bool flg;
    string ss;
    for(int i=0; i<ns-nt+1; i++) {
        flg = true;
        for(int j=0; j<nt; j++) {
            if(S[i+j] != T[j] && S[i+j] != '?') {
                flg = false;
            }
        }
        cout << endl;
        if (flg) {
            ss = S;
            ss.replace(i, nt, T);
        }
    }

    if(ss == "") {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    for(int i=0; i<ss.size(); i++) {
        if(ss[i] == '?') {
            cout << 'a';
        }
        else {
            cout << ss[i];
        }
    }
}