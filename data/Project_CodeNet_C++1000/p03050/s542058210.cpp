#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
#include<map>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
const ll MOD =  1000000007;
const ll INF =  1LL << 60;
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