#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int T[35][MAX];
int L[30];

int main(){
    int N, C;
    cin >> N >> C;

    rep(i, N) {
        int s, t, c;
        cin >> s >> t >> c;
        s--, t, c--;
        if (s == t) {
            T[c][s] ^= 1;
        } else {
            T[c][s] ^= 1;
            T[c][t] ^= 1;
        }
    }

    int ans = 0;
    rep(i, MAX) {
        int res = 0;
        rep(j, C) {
            L[j] ^= T[j][i];
            if (L[j]) res++;
        }
        ans = max(ans, res);
    }

    cout << ans << endl;
}