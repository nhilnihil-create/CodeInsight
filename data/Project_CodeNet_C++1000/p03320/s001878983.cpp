#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define dump(val) cerr << __LINE__ << ":\t" << #val << " = " << (val) << endl

using namespace std;

typedef long long int lli;
typedef pair<lli, lli> pll;

template<typename T>
vector<T> make_v(size_t a, T b) {
    return vector<T>(a, b);
}

template<typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

int digit(lli n) {
    int res = 0;
    do {
        res += n % 10;
        n /= 10;
    } while (n != 0);
    return res;
}

int main() {
    lli K;
    cin >> K;
    //*
    vector<pll> candidates;

    lli bs = 0;
    REP(d, 0, 13) {
        REP(i, 1, 1000) {
            lli n = 9 * bs + (9 * bs + 1) * i;
            candidates.push_back({n, digit(n)});
        }
        bs = bs * 10 + 1;
    }

    sort(begin(candidates), end(candidates));
    candidates.erase(unique(begin(candidates), end(candidates)), end(candidates));

    //dump((*rbegin(candidates)).first);

    int cnt = 0;
    REP(i, 0, candidates.size()) {
        if (cnt >= K) {
            break;
        }
        pll ans = candidates[i];
        bool ok = true;
        REP(j, i + 1, candidates.size()) {
            pll c = candidates[j];
            if (ans.first * c.second > ans.second * c.first) {
                ok = false;
            }
        }
        if (ok) {
            cnt++;
            cout << ans.first << endl;
        }
    }
    //*/
    /*
    int cnt = 0;
    REP(i, 1, 10000000) {
        bool ok = true;
        REP(j, i + 1, 1000000) {
            if (i * digit(j) > j * digit(i)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cnt++;
            cout << "#" << cnt << " " << i << endl;
        }
    }
    //*/
    return 0;
}
