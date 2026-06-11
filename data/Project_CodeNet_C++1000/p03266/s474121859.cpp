#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%lld",&x);

int main(){
    ll n, k, cnt1 = 0, cnt2 = 0, ans = 0;
    sc(n) sc(k)
    for (int i = 1; i <= n; i++){
        if (i%k == 0) cnt1++;
        if (i%k == k/2) cnt2++;
    }
    ans += cnt1 * cnt1 * cnt1;
    if (k%2 == 0) ans += cnt2 * cnt2 * cnt2;
    cout << ans << endl;
    return 0;
}