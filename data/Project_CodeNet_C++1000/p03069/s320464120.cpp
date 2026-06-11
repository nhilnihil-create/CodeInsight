#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    string S; cin >> S;
    int L = 0, R = 0;
    rep(i,N) if (S[i] == '.') R++;
    ll mi = L + R;
    rep(i,N) {
        if (S[i] == '#') L++;
        else R--;
        if (mi > L+R) {
            mi = L+R;
        }
    }
    cout << mi << endl;
}
