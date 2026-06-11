#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N; cin >> N;
    string S; cin >> S;
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int k; cin >> k;
        int d = 0, m = 0;
        long long pat = 0, ans = 0;
        for (int l = 0, r = 0; r < S.size(); r++) {
            if (S[r] == 'D') d++;
            if (S[r] == 'M') m++, pat += d;
            if (S[r] == 'C') ans += pat;
            if (r - l != k-1) continue;
            if (S[l] == 'D') d--, pat -= m;
            if (S[l] == 'M') m--;
            l++;
        }
        cout << ans << '\n';
    }
    return 0;
}