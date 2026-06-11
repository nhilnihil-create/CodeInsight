#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N; string S; cin >> N >> S;

    int sumw = count(ALL(S), '.');
    int ans = sumw, b = 0, w = 0;
    REP(i, 0, N) {
        if (S[i] == '.') w++;
        else b++;

        ans = min(ans, b + sumw - w);
    }
    cout << ans << endl;

    return 0;
}