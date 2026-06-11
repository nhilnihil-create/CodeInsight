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
    int N;
    cin >> N;
    vi A(N);
    for (auto &&e: A) {
        cin >> e;
        e--;
    }

    {
        bool ok = true;
        FOR(i, 1, N) {
            if (A[i - 1] >= A[i])
                ok = false;
        }

        if (ok) return 1;
    }

    int lb = 1;
    int ub = 1e9 + 10;
    while (ub - lb > 1) {

        int med = ((ll) ub + lb) / 2;
        map<int, int> mp;
        FOR(i, 1, N) {
            if (A[i - 1] >= A[i]) {
                // erase A[i]+1
                auto aft = mp.upper_bound(A[i]);
                mp.erase(aft, end(mp));

                mp[A[i]]++;

                int e = A[i];
                while (mp[e] >= med && e > 0) {
                    mp[e - 1] += mp[e] / med;
                    mp[e] = mp[e] % med;
                    e--;
                }
            }
        }

        if (mp[0] >= med) {
            lb = med;
        } else {
            ub = med;
        }
    }

    return ub;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cout << solve() << endl;
//    solve();
    return 0;
}
