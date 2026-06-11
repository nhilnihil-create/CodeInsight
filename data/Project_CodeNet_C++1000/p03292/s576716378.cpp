#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    vector<ll> a(3);
    rep(i, 0, 3) cin >> a[i];
    ll ans = 1e18;
    do {
        ans = min(ans, abs(a[0]-a[1])+abs(a[1]-a[2]));
    } while(next_permutation(a.begin(), a.end()));
    cout << ans << endl;
    return 0;
}