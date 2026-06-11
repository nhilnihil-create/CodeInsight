#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

signed main(){
    string s;
    ll K;
    set<string> st;
    cin >> s >> K;
    ll N = s.length();
    REP(i, N){
        FOR(j, 1, K + 1){
            if(i + j > N) continue;
            st.insert(s.substr(i, j));
        }
    }
    auto itr = st.begin();
    REP(i, K - 1){
        itr++;
    }
    PRINT(*itr);
    return 0;
}