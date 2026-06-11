#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1007654321
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }


int main() {
    string S; cin >> S;
    int N = sz(S);
    int cnt = 1;
    if(S[0] == '0' || S[N - 1] == '1') {
        cout << "-1\n";
        return 0;
    }
    bool same = true;
    for(int i = 0; i < N - 1; ++i) {
        if(S[i] != S[N - 2 - i]) {
            same = false;
            break;
        }
    }
    if(!same) {
        cout << "-1\n";
        return 0;
    }
    vector<int> body;
    vector<pii> edges;
    for(int i = 0; i < N; ++i) {
        if(S[i] == '1') body.push_back(i);
    }
    body.push_back(N - 1);
    for(int i = 0; i < sz(body) - 1; ++i) {
        edges.push_back({body[i], body[i + 1]});
    }
    for(int i = 0, j = 0; i < N; ++i) {
        if(i == body[j]) ++j;
        else {
            edges.push_back({i, body[j]});
        }
    }
    for(auto &e : edges) cout << e.first + 1 << " " << e.second + 1 << "\n";
}