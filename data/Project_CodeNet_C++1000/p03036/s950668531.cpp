#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int r, d, x; cin >> r >> d >> x;

    V<ll> ans(11);
    ans[0] = x;
    for(int i = 0; i < 10; i++){
        ans[i + 1] = ans[i] * r - d;
    }
    for(int i = 1; i <= 10; i++){
        cout << ans[i] << endl;

    }

    return 0;
}
