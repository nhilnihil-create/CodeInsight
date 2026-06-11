#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string Sd, T;
    cin >> Sd >> T;
    int s = Sd.size();
    int t = T.size();
    if (s < t) {
        cout << "UNRESTORABLE" << "\n";
        return 0;
    }
    bool res = false;
    for (int i=s-t;i>=0;i--){
        bool ok = true;
        for (int x=0;x<t;x++){
            if (Sd[i+x] == '?') continue;
            if (Sd[i+x] != T[x]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            for (int x=0;x<t;x++){
                if (Sd[i+x] == '?') {
                    Sd[i+x] = T[x];
                }
            }
            res = true;
            break;
        }
    }
    if (res) {
        for (int i=0;i<s;i++){
            if (Sd[i]=='?') Sd[i] = 'a';
        }
        cout << Sd << "\n";
    } else {
        cout << "UNRESTORABLE" << "\n";
    }
}