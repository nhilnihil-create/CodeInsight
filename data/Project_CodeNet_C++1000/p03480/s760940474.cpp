#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    int N = S.size();
    int res = 1001001001;
    for(int i=1; i<N; ++i) {
        if(S[i-1] != S[i]) res = min(res, max(i, N-i));
    }
    if(res == 1001001001) res = N;
    cout << res << endl;
}