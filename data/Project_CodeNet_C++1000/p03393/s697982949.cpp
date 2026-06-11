#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    vector<bool> a(26, false);
    rep(i, N) {
        a[S[i] - 'a'] = true;
    }
    rep(i, 26) {
        if (a[i]) continue;
        cout << S << (char)(i + 'a') << "\n";
        return 0;
    }
    int i = -1;
    rep(k, N - 1) {
        if (S[k] < S[k + 1]) i = k;
    }
    if (i == -1) {
        cout << "-1\n";
        return 0;
    }
    int j;
    rep(k, N) if (S[k] > S[i]) j = k;
    cout << S.substr(0, i) << S[j] << "\n"; 
}