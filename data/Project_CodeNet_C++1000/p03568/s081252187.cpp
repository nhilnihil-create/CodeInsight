#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int INF = 1001001001;
const double PI = acos(-1);

#define rep(i, n)  for(int i=0;i<(n);++i)
#define all(x) (x).begin(),(x).end()

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n, 0);
    rep(i, n) cin >> a[i];
    int ans = 1;
    int ansn = 1;
    rep(i, n) {
        ans *= 3;
        if (a[i] % 2 == 0) ansn *= 2;
    }

    ans -= ansn;

    cout << ans << endl;
}
