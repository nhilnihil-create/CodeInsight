#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%lld",&x);
int main(){
    ll n, k, ans = 0;
    sc(n) sc(k)
    for (int i = k + 1; i <= n; i++){ 
        ans += (i - k) * (n / i);
        if (n % i >= k) ans += n % i - k + 1;
    }
    if (k == 0) ans -= n;
    cout << ans << endl;
    return 0;
}