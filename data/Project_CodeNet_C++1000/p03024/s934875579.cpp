#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (int)(b); ++i)
#define FORR(i, a, b) for(int i = (a); i >= (int)(b); --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
typedef vector<P> VP;
typedef vector<PL> VPL;
typedef vector<string> VS;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int k = s.size();
    int o_cnt = 0;
    REP(i, k)if(s[i] == 'o') o_cnt++;
    if(15 - k + o_cnt >= 8) cout << "YES" << ln;
    else cout << "NO" << ln;
    return 0;
}
