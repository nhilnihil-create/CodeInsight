#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef long long ll;

int main(){
    ll k, a, b;
    cin >> k >> a >> b;

    if (b-a <= 2){
        cout << k + 1 << endl;
        return 0;
    }

    ll biscuit = 1;

    k = k - a + 1;

    ll ans = a;
    ans += (b-a) * (k / 2); 
    if (k%2 == 1) ans++;

    cout << ans << endl;


}