#include<bits//stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, x, y,z,w,h, sum= 1, ans = 0;
ll enum_div(ll n) {
    vector<int> ret;
    ll cnt = 0;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0 && n % (n / i - 1) == i) {
            cnt += n / i - 1;
        }
    }
    return cnt;
}
int main() {
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    cout << enum_div(n) << endl;
}