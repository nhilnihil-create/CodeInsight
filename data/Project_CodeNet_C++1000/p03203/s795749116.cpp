#include <bits/stdc++.h>

using namespace std;

#define REP(var, n)  for (decltype(n) var = 0; var < (n); var++)
#define RREP(var, n)  for (auto var = n - 1; var != static_cast<decltype(var)>(-1); var--)
#define FOR(var, a, b)  for (auto var = (a); var < (b); var++)
#define RFOR(var, a, b)  for (auto var = b - 1; var != a; var--)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define all(c) begin(c),end(c)

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}


template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    return os << '(' << p.first << ',' << p.second << ')';
}


const int INF = 1 << 29;

auto solve() {
    int H, W, N;
    cin >> H >> W >> N;

    vector<set<int>> obs(W + 2);
    REP(_i, N) {
        int r, c;
        cin >> r >> c;
        obs[c].insert(r);
    }

    int current_r = 1;
    int res = H;
    FOR(i, 1, W + 1) {
//        cerr << " nm down (r,c) " << current_r << "," << i << endl;
//        if (i > H)
//            break;
        auto o = obs[i];
//        cerr << " --- " << i << "  - " << current_r << endl;
        for (auto &&e:o) {
//            cerr << e << endl;
            // simple obs
            if (e >= current_r) {
                res = min(res, e - 1);
//                cerr << " --sa- " << current_r << "," << e << endl;
            }
        }

//        cerr << "  down" <<endl;

        // force down
        {
            auto o = obs[i + 1];
            for (auto &&e: o) {
                if (e == current_r + 1) {
//                    cerr << "   add " << endl;
                    current_r++;
                }
            }
            current_r++;
        }
    }

    return res;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cout << solve() << endl;
//    solve();
    return 0;
}
