#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, std::string S) {
    size_t ans = 0;
    for (ll i = 1; i < N; i++) {
        string X = S.substr(0, i);
        string Y = S.substr(i);
        set<char> xset;
        set<char> yset;
        set<char> result;
        rep(j, X.length()) { xset.insert(X[j]); }
        rep(j, Y.length()) { yset.insert(Y[j]); }
        set_intersection(xset.begin(), xset.end(), yset.begin(), yset.end(), inserter(result, result.end()));
        ans = max(ans, result.size());
    }
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::string S;
    std::cin >> S;
    solve(N, S);
    return 0;
}
