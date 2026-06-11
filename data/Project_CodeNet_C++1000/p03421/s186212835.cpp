#include <bits/stdc++.h>
#define fst first
#define snd second
#define rep(n) for(lint I = 0; (I) < (lint)(n); ++(I))
#define repeat(i, n) for(lint i = 0; (i) < (lint)(n); ++(i))
#define repeat_to(i, n) for(lint i = 0; (i) <= (lint)(n); ++(i))
#define repeat_from(i, m, n) for(lint i = (m); (i) < (lint)(n); ++(i))
#define repeat_from_to(i, m, n) for(lint i = (m); (i) <= (lint)(n); ++(i))
#define repeat_reverse_from_to(i, m, n) for(lint i = (m); (i) >= (lint)(n); --(i))
#define el cout<<endl
#define dump(x) cout<<" "<<#x<<"="<<x
#define vdump(v) for(size_t I=0; I<v.size(); ++I){cout<<" "<<#v<<"["<<I<<"]="<<v[I];} cout<<endl
using namespace std;
using lint = long long;
using ld = long double;

int main(void) {
    lint n, a, b;
    cin >> n >> a >> b;
    
    if (n < a + b -1) {
        cout << "-1" << endl;
        return 0;
    }
    if (n > a * b) {
        cout << "-1" << endl;
        return 0;
    }
    
    auto getnum = [&](lint i, lint j) -> lint {
        return a * (b - 1 - i) + 1 + j;
    };
    
    vector<lint> s;
    lint c = n - b;
    
    repeat (i, b) {
        lint t = getnum(i, 0);
        s.emplace_back(t);
        if (c <= 0) continue;
        if (c > 0) {
            if (c <= a - 1) {
                repeat (j, c) {
                    t = getnum(i, j+1);
                    s.emplace_back(t);
                }
                c = 0;
            }
            else {
                repeat (j, a - 1) {
                    t = getnum(i, j+1);
                    s.emplace_back(t);
                }
                c -= (a - 1);
            }
        }
    }
    
    // 座標圧縮(配列sの値を破壊的に変更する)
    // ソート → 一意要素を前に → 後半に残る重複要素を削除 → 二分探索で元の数字のindexを調べる
    auto t = s;
    sort(t.begin(), t.end());
    auto it = unique(t.begin(), t.end());
    t.erase(it, t.end());
    for(auto &e: s) {
        e = lower_bound(t.begin(), t.end(), e) - t.begin();
    }
    
    repeat (i, s.size()) {
        cout << s[i]+1 << " ";
    }
}