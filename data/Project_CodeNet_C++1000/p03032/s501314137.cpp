#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, K;
ll V[100];

signed main(){
    cin >> N >> K;
    REP(i, N) cin >> V[i];
    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    REP(i, N + 1){
        REP(j, N + 1){
            ll n = i + j;
            if(n > min(N, K)) continue;
            REP(k, i) que.push(V[k]);
            REP(k, j) que.push(V[N - 1 - k]);
            while(n < K && !que.empty()){
                if(que.top() < 0) que.pop();
                n++;
            }
            ll sum = 0;
            while(!que.empty()){
                sum += que.top();
                que.pop();
            }
            ans = max(ans, sum);
        }
    }
    PRINT(ans);
    return 0;
}