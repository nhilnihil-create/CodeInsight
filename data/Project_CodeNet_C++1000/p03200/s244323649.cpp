#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

ll solve(string S) {
    int N = S.size();
    reverse(S.begin(), S.end());
    ll cnt = 0;
    while (true) {
        ll prev = cnt;
        rep(i,N-1) {
            if (S[i] == 'W' && S[i+1] == 'B') {
                swap(S[i], S[i+1]);
                cnt++;
                printf("%s\n", S.c_str());
            }
        }
        if (cnt == prev) break;
    }
    return cnt;
}

ll solve2(string S) {
    int N = S.size();
    ll cnt = 0, cn2 = 0;
    rep(i,N) if (S[i] == 'W') cnt++; else break;
    for (int i = N - 1; i >= 0; i--) if (S[i] == 'B') cn2++; else break;
    N -= cnt + cn2;
    S = S.substr(cnt, N);
    int s = 0;
    reverse(S.begin(), S.end());
    cnt = 0;
    rep(i,N) {
        if (S[i] == 'W') {
            cnt += N-1 -s -i;
            s++;
        }
    }
    return cnt;
}

int main() {
    string S; cin >> S;
    cout << solve2(S) << endl;
}
