#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
using ll = long long;
int main() {
    int n;
    scanf("%d", &n);

    ll m = 0, a = 0, r = 0, c = 0, h = 0;  // それぞれの頭文字を持つ人の数
    string s;
    rep(i, n){
        cin >> s;
        if (s[0] == 'M') m++;
        if (s[0] == 'A') a++;
        if (s[0] == 'R') r++;
        if (s[0] == 'C') c++;
        if (s[0] == 'H') h++;
    }

    ll D[5]; //各アルファベットを頭文字荷物名前の個数を入れた配列
    D[0] = m, D[1] = a, D[2] = r, D[3] = c, D[4] = h;

    // 組み合わせ（縦に見ると分かりやすい）。制約から重複がないことが前提。
    int P[10] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 2};
    int Q[10] = {1, 1, 1, 2, 2, 3, 2, 2, 3, 3};
    int R[10] = {2, 3, 4, 3, 4, 4, 3, 4, 4, 4};

    ll res = 0;
    rep(d, 10) res += D[P[d]] * D[Q[d]] * D[R[d]];
    printf("%lld\n ", res);
}