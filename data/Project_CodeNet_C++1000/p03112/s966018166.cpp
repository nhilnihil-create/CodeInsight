#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

const long long INF = 100100100100;

int main() {
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<long long> s(A + 2), t(B + 2), x(Q);
    s[0] = -INF;
    s[A + 1] = INF;
    t[0] = -INF;
    t[B + 1] = INF;
    rep(i, A) cin >> s[i + 1];
    rep(i, B) cin >> t[i + 1];
    rep(i, Q) cin >> x[i];
    
    rep(i, Q) {
        auto s_iter1 = upper_bound(s.begin(), s.end(), x[i]);
        auto s_iter0 = s_iter1 - 1;
        auto t_iter1 = upper_bound(t.begin(), t.end(), *s_iter0);
        auto t_iter0 = t_iter1 - 1;
        auto t_iter3 = upper_bound(t.begin(), t.end(), *s_iter1);
        auto t_iter2 = t_iter3 - 1;
        long long s_0 = min(abs(*s_iter0 - *t_iter0), abs(*s_iter0 - *t_iter1));
        long long s_1 = min(abs(*s_iter1 - *t_iter2), abs(*s_iter1 - *t_iter3));
        long long tj = min(abs(x[i] - *s_iter0) + s_0, abs(x[i] - *s_iter1) + s_1);
        //変数名使い回し（よくない）
        s_iter1 = upper_bound(t.begin(), t.end(), x[i]);
        s_iter0 = s_iter1 - 1;
        t_iter1 = upper_bound(s.begin(), s.end(), *s_iter0);
        t_iter0 = t_iter1 - 1;
        t_iter3 = upper_bound(s.begin(), s.end(), *s_iter1);
        t_iter2 = t_iter3 - 1;
        s_0 = min(abs(*s_iter0 - *t_iter0), abs(*s_iter0 - *t_iter1));
        s_1 = min(abs(*s_iter1 - *t_iter2), abs(*s_iter1 - *t_iter3));
        long long jt = min(abs(x[i] - *s_iter0) + s_0, abs(x[i] - *s_iter1) + s_1);
        cout << min(jt, tj) << endl;
    }
}
