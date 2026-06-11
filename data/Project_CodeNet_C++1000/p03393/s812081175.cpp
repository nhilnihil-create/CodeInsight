#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    string S; cin >> S;
    int N = S.size();
    set<char> C;
    for (char c = 'a'; c <= 'z'; c++) C.insert(c);
    rep(i,N) C.erase(S[i]);
    if (!C.empty()) {
        S.push_back(*C.begin());
    } else { // empty
        int i = N-1;
        while (i > 0 && S[i] < S[i-1]) i--;
        if (i == 0) { // The last word. No next.
            cout << -1 << endl;
            return 0;
        }
        string prefix = S.substr(0, i);
        string suffix = S.substr(i, N - i);
        sort(suffix.begin(), suffix.end());
        auto x = lower_bound(suffix.begin(), suffix.end(), prefix[i-1]);
        prefix[i-1] = *x;
        S = prefix;
    }
    cout << S << endl;
}