#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    
    vector<int> U(26);
    rep(i, 26) U[i] = 'a' + i;
    rep(i, S.size()) rep(j, 26) {
        if (T[i] == U[j]) {
            swap(U[S[i] - 'a'], U[j]);
        }
    }
    rep(i, S.size()) S[i] = U[S[i] - 'a'];
    if (S == T) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
