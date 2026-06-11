#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    string S; cin >> S;
    int mi = S.size();
    rep(i, S.size()-1) {
        if (S[i] != S[i+1]) {
            int T = max(i+1, (int)S.size()-(i+1));
            mi = min(mi, T);
        }
    }
    cout << mi << endl;
}
