#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

pii f(pii a, pii b){
    int p[] = {a.first, a.second, b.first, b.second};
    sort(p, p+4, greater<int>());
    return pii(p[0], p[1]);
}

int main(){
    int N;
    cin >> N;
    int A[1<<N];
    pii dp[1<<N];
    rep(i, (1<<N)){
        cin >> A[i];
        dp[i] = pii(A[i], 0);
    }
    rep(j, N){
        rep3(i, (1<<N)-1, 0){
            if(i & (1<<j)){
                //i & ~(1<<j) = iの下からjビット目を0にしたもの
                dp[i] = f(dp[i], dp[i & ~(1<<j)]);
            }
        }
    }
    int now = 0;
    rep2(i, 1, (1<<N)-1){
        now = max(now, dp[i].first + dp[i].second);
        cout << now << endl;
    }
}