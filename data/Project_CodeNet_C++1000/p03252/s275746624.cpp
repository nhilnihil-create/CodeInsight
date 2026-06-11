#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    string S, T; cin >> S >> T;
    int size = S.size();
    vector<int> sc(30, 100);
    vector<int> tc(30);
    bool ok = true;
    rep(i, size){
        int s = S[i] - 'a';
        int t = T[i] - 'a';
        if(sc[s] == 100 && tc[t] == 0){
            sc[s] = t;
            tc[t] = 1;
            continue;
        } else if (sc[s] == t){
            continue;
        } else {
            ok = false;
            break;
        }
    }

    if(ok){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}