#include <bits/stdc++.h>
using namespace std;
const long long INF = 100000000000000;
const int MOD = 1000000007;
#define rep(i, a) REP(i, 0, a)
#define REP(i, a, b) for(int i = a; i < b;i++)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<P> vp;



int main() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    bitset<2001*2001> dp;
    dp[0] = 1;
    int sum = 0;
    rep(i, n){
        sum += a[i];
        dp = dp | (dp << a[i]);
    }
    for(int i = (sum + 1) / 2;i <= sum;i++){
        if(dp[i]){
            cout << i << endl;
            break;
        }
    }
}