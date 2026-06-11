#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define ALL(vec) (vec).begin(), (vec).end()
#define REVALL(vec) (vec).rbegin(), (vec).rend()

#define fst first
#define pb push_back

const int MOD = (int)1e9 + 7;
const int INF = numeric_limits<int>::max();

signed main() {
    int N, H;

    cin >> N >> H;

    vector<int> As(N);
    vector<int> Bs(N);
    REP(i, N) {
        cin >> As.at(i) >> Bs.at(i);
    }

    // 一番良い刀(a)よりも投げてダメージを与えられるものがあれば、
    // 投げ続ける

    // 一番良い刀を極力振る

    // トドメは一番良い刀の投げ

    int best_katana_a = 0;
    int best_katana_b = 0;
    int best_katana_ind = 0;

    REP(i, N) {
        if (As.at(i) > best_katana_a) {
            best_katana_a = As.at(i);
            best_katana_b = Bs.at(i);
            best_katana_ind = i;
        } else if (As.at(i) == best_katana_a && Bs.at(i) < best_katana_b) {
            best_katana_a = As.at(i);
            best_katana_b = Bs.at(i);
            best_katana_ind = i;
        }
    }

    // 刀が残っているかどうか
    vector<bool> remain(N, true);

    // bの大きい順にソートしておこう
    vector<pair<int, int>> katana_for_throw;
    REP(i, N) {
        if (Bs.at(i) > best_katana_a && i != best_katana_ind) {
            pair<int,int> p = make_pair(Bs.at(i), i);
            katana_for_throw.pb(p);
        }
    }
    sort(REVALL(katana_for_throw));

    int ans = 0;

    for(auto p : katana_for_throw) {
        int b = p.first;

        H -= b;
        ans += 1;

        if (H <= 0) {
            cout << ans << endl;
            return 0;
        }
    }

    if (H > best_katana_b) {
        int cnt = (H - best_katana_b) / best_katana_a;
        H -= best_katana_a * cnt;
        ans += cnt;
    }

    // a + b もしくは b
    if (H > best_katana_b) {
        ans += 2;
    } else {
        ans += 1;
    }

    cout << ans << endl;
}
