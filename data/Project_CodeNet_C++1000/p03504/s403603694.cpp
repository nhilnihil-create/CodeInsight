#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int N, c;
vector<int> S, T, C;

vector<tuple<int, int, int>> w;
map<int, set<int>> ms, mt;


void input() {
    cin >> N >> c;
    S = T = C = vector<int>(N);
    rep(i, N) cin >> S[i] >> T[i] >> C[i];
}


int main() {
    input();
    rep(i, N) {
        w.push_back(make_tuple(S[i], 0, C[i]));
        w.push_back(make_tuple(T[i], 1, C[i]));
        ms[S[i]].insert(C[i]);
        mt[T[i]].insert(C[i]);
    }
    sort(w.begin(), w.end());
    int ans = 0;
    int s = 0;
    for (auto t : w) {
        if (get<1>(t) == 0) {
            if (mt[get<0>(t)].count(get<2>(t)) == 0) s++;
        } else {
            if (ms[get<0>(t)].count(get<2>(t)) == 0) s--;
        }
        ans = max(ans, s);
    }
    cout << ans << endl;
}
