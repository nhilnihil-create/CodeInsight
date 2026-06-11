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


auto solve() {
    int N;
    cin >> N;

    int SIZE = N * 2 + 10;

    vll sumC(SIZE, 0);
    vll sumM(SIZE, 0);
    vll sumBef(SIZE, 0);


    string S;
    cin >> S;
    S.reserve(N);

    REP(i, N) {
        sumC[i + 1] = sumC[i] + (int) (S[i] == 'C');
        sumM[i + 1] = sumM[i] + (int) (S[i] == 'M');
        sumBef[i + 1] = sumBef[i];
        if (S[i] == 'C')
            sumBef[i + 1] += sumM[i + 1];
    }
    FOR(i, N + 1, SIZE) {
        sumC[i] = sumC[i - 1];
        sumM[i] = sumM[i - 1];
        sumBef[i] = sumBef[i - 1];
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int k;
        cin >> k;

        ll res = 0;
        REP(i, N + 1) {
            if (S[i] == 'D') {
                ll diffC = sumC[i + k] - sumC[i];
                ll diffBef = sumBef[i + k] - sumBef[i];
                res += diffBef - diffC * sumM[i + 1];
            }
        }
        cout << res << endl;
    }

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

//    cout << solve() << endl;
    solve();
//REP(i,(int)1e6) cout << (char)('A' + (i % 26));
//cout <<endl;
    return 0;
}
