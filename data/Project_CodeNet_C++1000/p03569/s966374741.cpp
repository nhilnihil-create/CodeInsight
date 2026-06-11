#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    auto i = 0;
    auto bi = s.size()-1;
    auto ans = 0;
    while(i < bi) {
        if(s[i] == s[bi]) {
            i++;
            bi--;
            continue;
        }
        if(s[i] != 'x' && s[bi] != 'x' && s[i] != s[bi]) {
            cout << -1 << endl;
            return;
        }
        if((s[i] == 'x' || s[bi] == 'x') && s[i] != s[bi]) {
            if(s[i] == 'x') i++;
            if(s[bi] == 'x') bi--;
            ans++;
            continue;
        }
    }
    cout << ans << endl;

}

int main() {
    solve();
    return 0;
}