#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (1<<29);
const int INFF = 0x7fffffff;
const ll LINF = (1ll<<60);
const ll LINFF = 0x7fffffffffffffff;
const long double PI = 3.14159265359;

#define _fi(n) for(int i = 0;i < n;i++)
#define _fj(n) for(int j = 0;j < n;j++)
#define _fk(n) for(int k = 0;k < n;k++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define prec(x) cout << fixed << setprecision(x)
#define sz(x) (int)x.size()
#define _log2(x) 31-__builtin_clz(x)

#define hash sodnf9843bsd
#define right iadjfof23n3okd
#define pqueue priority_queue
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define len length
#define endl '\n'

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll a, ll b){return uniform_int_distribution<ll>(a, b)(rng);}

int n;
double dp[333][333][333] = {};
bool vis[333][333][333] = {};

double solve(int a, int b, int c){
    if (a+b+c == 0) return 0;
    if (a < 0 || b < 0 || c < 0) return 0;

    if (vis[a][b][c] == false){
        vis[a][b][c] = true;

        dp[a][b][c] = 1;
        dp[a][b][c] += (double)a/n*solve(a-1, b, c);
        dp[a][b][c] += (double)b/n*solve(a+1, b-1, c);
        dp[a][b][c] += (double)c/n*solve(a, b+1, c-1);
        dp[a][b][c] *= (double)n/(a+b+c);
    }
    return dp[a][b][c];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cnt[5] = {};
    cin>>n;
    _fi(n){
        int x;cin>>x;
        cnt[x]++;
    }

    prec(10);
    cout << solve(cnt[1], cnt[2], cnt[3]) << endl;

    return 0;
}
