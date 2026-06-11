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
    int n;
    cin >> n;
    long double a[n], ave = 0, mn = INF;
    rep(i, n) cin >> a[i], ave += a[i];
    ave /= n;

    rep(i, n) mn = min(abs(a[i] - ave), mn);


    rep(i, n) {
        if (abs(a[i]-ave) == mn){
            cout << i << endl;
            return 0;
        }
    }


    return 0;
}
