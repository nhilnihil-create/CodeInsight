#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)cin >> a[i];
    ll ans = 0;
    int r = 0;
    int x = a[0];
    int sum = a[0];
    for(int l = 0; l < n; l++){
        if(r < n){
            while(x == sum){
                r++;
                if(r == n)break;
                x ^= a[r];
                sum += a[r];
            }
        }
        ans += r - l;
        x ^= a[l];
        sum -= a[l];
    }
    cout << ans << endl;
}