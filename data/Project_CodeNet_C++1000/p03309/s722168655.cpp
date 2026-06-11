#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll n;
vector<ll> a;

int main(){
    cin >> n;
    a.resize(n);
    rep(i, 0, n){
        cin >> a[i];
        a[i] -= i;
    }
    sort(a.begin(), a.end());
    ll b = a[n/2];
    ll ans = 0;
    rep(i, 0, n) ans += abs(a[i]-b);
    cout << ans << endl;
    return 0;
}