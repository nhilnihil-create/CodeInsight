#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

ll get(ll x, vector<ll> &D) {
    ll M = D.size();
    if ((x + 100000000000LL) % 2 == 1) {
        return ((1LL << M) - 1 - x) / 2;
    } else {
        return (1LL << (M - 1)) | ((1LL << (M - 1)) - (x + 1)) / 2;
    }
}

void solve() {
    ll N;
    cin >> N;
    vector<pii> P;
    set<ll> S;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        P.push_back({x + y, x - y});
        S.insert((x + y + 1000000000000LL) % 2);
        S.insert((x - y + 1000000000000LL) % 2);
    }

    if (S.size() == 2) {
        cout << "-1" << endl;
        return;
    }

    ll M = 39;
    vector<ll> D(M);
    for (int i = 0; i < M; i++) {
        D[i] = 1LL << i;
    }

    vector<ll> D_ = D;

    if (*S.begin() % 2 == 0) {
        D_.push_back(1);
        M++;
    }

    cout << D_.size() << endl;
    for (int i = 0; i < D_.size(); i++) {
        cout << D_[i];
        if (i + 1 != D_.size()) {
            cout << " ";
        }
    }
    cout << endl;
    
    for (int i = 0; i < N; i++) {
        ll k1 = get(P[i].first, D_);
        ll k2 = get(P[i].second, D_);
        for (ll i = 0; i < M; i++) {
            ll k = ((k1 >> i & 1) << 1) | (k2 >> i & 1);
            if (k == 0) {
                cout << "R";
            } else if (k == 1) {
                cout << "U";
            } else if (k == 2) {
                cout << "D";
            } else {
                cout << "L";
            }
        }
        cout << endl;
    }
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}