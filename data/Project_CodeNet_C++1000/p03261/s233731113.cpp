#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
typedef long long ll;
typedef long double ld;
const long long INF = 1e18;
# define len(x) ((int)(x).size())
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define foreps(i, m, n) for(int i = m;i < n;i++)
# define ALL(x) (x).begin(), (x).end()
# define rall(x) (x).rbegin(), (x).rend()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

bool reverseStr(string mem, string sx) {
    reverse(mem.begin(), mem.end());
    if (mem.at(0) == sx.at(0)) return true;
    else return false;
}

int main() {
    ll N; cin >> N;
    map<string, int> ch;
    vector<string> W(N);
    rep(i, N) {
        cin >> W.at(i); ch[W[i]]++;
    }
    rep(i, N) {
        if (2 <= ch[W[i]]) {
            cout << "No" << endl;
            return 0;
        }
    }

    string mem = W.at(0);
    reps(i, N - 1) {
        string sx = W.at(i);
        if (!reverseStr(mem, sx)) {
            cout << "No" << endl;
            return 0;
        }
        mem = W.at(i);
    }
    cout << "Yes" << endl;
}