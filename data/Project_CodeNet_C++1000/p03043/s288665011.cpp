#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    int n, k;
    cin >> n >> k;
    long double ans = 0;

    rep(i, n){
        int p = i + 1;
        int l = 0;
        while(1){
            if (p * (int)(pow(2,l)) >= k) break;
            l++;
        }
        ans += 1 / pow(2, l);
    }

    cout << fixed << setprecision(15) << ans / n << endl;

    return 0;
}
