#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int N;
vector<string> S;


void input() {
    cin >> N;
    S = vector<string>(N);
    rep(i, N) cin >> S[i];
}


ll comb3(ll n) {
    ll ret = n * (n - 1) * (n - 2) / 6;
    return ret;
}


ll comb2(ll n) {
    return n * (n - 1) / 2;
}


int main() {
    input();
    set<char> s{'M', 'A', 'R', 'C', 'H'};
    map<char, int> m;
    int n = 0;
    rep(i, N) {
        if (s.count(S[i][0])) {
            m[S[i][0]]++;
            n++;
        }
    }
    ll ans = comb3(n);
    for (auto p : m) {
        int v = p.second;
        ans -= comb2(v) * (n - v);
        ans -= comb3(v);
    }
    cout << ans << endl;
}
