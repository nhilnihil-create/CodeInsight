#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
//#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
/* -- template -- */

const int MAX = 1000100;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i)%MOD;//拡張euclid互除法によるi!の逆元計算
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(int n, int k) {
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD)%MOD;
}

int main() {
    int N, K;
    cin >> N >> K;
    int V[N];
    int ans = 0;
    rep(i, N) cin >> V[i];
    for(int a = 0; a <= K; ++a) {
        for(int b = 0; b <= K - a; ++b) {
            priority_queue<int, vector<int>, greater<int>> que;
            int tmp = 0;
            if(a + b > N) {
                rep(i, N)que.push(V[i]);
                rep(i, min(K - (a + b), N)){
                    if(que.top() < 0)
                        que.pop();
                    else
                        break;
                }

            }else {
                rep(i, a)que.push(V[i]);
                rep(i, b)que.push(V[N - 1 - i]);
                rep(i, min(K - (a + b), a + b)){
                    if(que.top() < 0)
                        que.pop();
                    else
                        break;
                }
            }
            while(!que.empty()) {
                tmp += que.top();que.pop();
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
}
