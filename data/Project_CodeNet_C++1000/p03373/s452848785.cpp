#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll ans = a * x + b * y;
    ll z = 0;
    
    for(int i = 0; i <= max(x, y); i++) {
        ll tmp = c * (i * 2);
        ll AA = max(z, x - i);
        ll BB = max(z, y - i);
        tmp += AA * a + BB * b;
        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}