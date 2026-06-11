/**
 * @author      : Luis Miguel Baez <es.luismiguelbaez@gmail.com>
 * @created     : August 22, 2020
 */

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ms(arr, value) memset(arr, value, sizeof(arr))
#define finally(value) {cout << value << '\n'; return;}
#define ll    int64_t

const int oo = int(1e9);
const ll lloo  = (ll)(1e18);
const int MAXN = int(1e5) + 10;

class Task {
public:
    int n, k;
    vector<int> A;

    bool dp[MAXN][3];

    int minimum = oo;

    bool go(int K, bool player) {
        if(K < minimum) return false;
        if(dp[K][int(player)]) return dp[K][int(player)];
        bool &ans = dp[K][int(player)];
        ans = false;
        for(int i = 1; i <= n; ++i){
            if(K < A[i]) continue;
            ans = !go(K-A[i], !player);
            if(ans) break;
        }
        return ans;
    }

    void solveOne(istream &in, ostream &out) {
        in >> n >> k;
        A.resize(n+1);
        for(int i = 1; i <= n; ++i){
            in >> A[i];
            minimum = min(minimum, A[i]);
        }
        ms(dp, false);
        bool ans = go(k, true);
        finally( (ans?"First":"Second") );
    }
    
    void solve(istream &in, ostream &out) {
        int t=1;
        while(t--) solveOne(in, out);
    }
};

auto main() -> int {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Task solver;
    istream &in(cin);
    ostream &out(cout);
    solver.solve(in, out);
    return 0;
}
