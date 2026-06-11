#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
constexpr int MOD = 1000000007;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p){os << "(" << p.first << ", " << p.second << ")"; return os;}

void solve() {
    int H, W, N;
    cin >> H >> W >> N;
    set<pii> P;
    vector<vector<int>> P2(H + 1);

    for (int i = 0; i < N; i++) {
        int y, x;
        cin >> y >> x;
        y--, x--;
        P2[y].push_back(x);
        P.insert({y, x});
    }
    
    int w = 0;
    for (int i = 0; i < H; i++) {
        for(int j = 0; j < P2[i + 1].size(); j++) {
            if (P2[i + 1][j] <= w) {
                cout << i + 1 << endl;
                return;
            }
        }
        if (P.find({i + 1, w + 1}) == P.end()) w++;
    }
    cout << H << endl;
    
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}