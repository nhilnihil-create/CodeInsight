#include <bits/stdc++.h>

#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"

using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;

template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

signed main(){
    int N, D[51];
    vector<int> T;
    bool visited[51];
    cin >> N;
    REP(i, N){
        cin >> D[i];
    }
    D[N] = 0;
    sort(D, D + N + 1);
    for(int s = 24; s >= 0; s--){
        vector<int> T;
        T.push_back(D[0]);
        int p = 0;
        FOR(i, 1, N + 1){
            if(D[i] - p < s){
                T.push_back((24 - D[i]) % 24);
            }else{
                T.push_back(D[i]);
                p = D[i];
            }
        }
        sort(ALL(T));
        int m = (24 - T[N]) % 24;
        FOR(i, 1, N + 1) m = min(m, T[i] - T[i - 1]);
        if(m >= s){
            PRINT(m);
            return 0;
        }
    }
    return 0;
}