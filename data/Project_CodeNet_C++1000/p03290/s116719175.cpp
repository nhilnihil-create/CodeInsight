#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int D, G;
    cin >> D >> G;
    G /= 100;
    int p[D], c[D];
    for(int i = 0; i < D; i++) {
        cin >> p[i] >> c[i];
        c[i] /= 100;
    }
    int ans = inf;
    for(int bit = 0; bit < (1 << D); ++bit) {
        vector<int> S;
        for(int i = 0; i < D; ++i) {
            if(bit & (1 << i)) {  // i が bit に入るかどうか
                S.push_back(i);
            }
        }

        int score = 0, solved = 0;
        bool used[D];

        for(int i = 0; i < D; i++) used[i] = false;
        for(int i = 0; i < S.size(); i++) {
            used[S[i]] = true;
            score += c[S[i]] + p[S[i]] * (S[i] + 1);
            solved += p[S[i]];
        }
        int tmp = D;
        while(score < G && tmp > 0) {
            tmp--;
            if(used[tmp]) continue;
            solved += min(p[tmp], (G - score + tmp) / (tmp + 1));
            score += (tmp + 1) * min(p[tmp], (G - score + tmp) / (tmp + 1));
        }
        if(score >= G) ans = min(ans, solved);
    }
    cout << ans << "\n";
    return 0;
}
