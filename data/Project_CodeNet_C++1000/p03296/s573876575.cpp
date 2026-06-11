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
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    int ans = 0;
    rep(i, n-1){
        if(a[i] == a[i+1]){
            a[i+1] = -1;
            ans++;
        }
    }
    cout << ans << endl;
}