#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, m, x;
    cin >> n >> m;
    ll ans = pow(2, m) * ((m * 1900) + (n-m) * 100);
    cout << ans << endl;
    return 0;
}