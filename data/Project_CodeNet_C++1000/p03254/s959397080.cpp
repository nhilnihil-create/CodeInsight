#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    ll sum = 0;
    rep(i, n)sum += a[i];
    if(sum == x)cout << n << endl;
    else{
        int ans = 0;
        sort(a.begin(), a.end());
        rep(i, n-1){
            if(x >= a[i]){
                x -= a[i];
                ans++;
            }
        }
        cout << ans << endl;
    }
    
}