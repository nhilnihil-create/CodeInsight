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
    int ans = x;
    for(int i = 1; i <= 10; i++){
        ans = r * ans - d;
        cout << ans << endl;
    }

    return 0;
}
