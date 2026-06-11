#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

constexpr ll INF = ll(1e+18) + 1;

int main() {
    int N;
    string S;
    ll ans = 0;
    ll count = 0;
    vector<int> X;
    vector<int> Y;
    
    cin >> N;
    cin >> S;

    rep(i, 26) {
        X.push_back(0);
        Y.push_back(0);
    }

    rep (i, (int)S.size()) {
        Y[S[i]-'a']++;
    }

    rep(i, (int)S.size()) {
        X[S[i]-'a']++;
        Y[S[i]-'a']--;
        count = 0;
        rep (j, (int)X.size()) {
            if (X[j] > 0 && Y[j] > 0) {
                count++;
            }
        }

        ans = max(ans, count);
    }

    cout << ans << endl;
}
