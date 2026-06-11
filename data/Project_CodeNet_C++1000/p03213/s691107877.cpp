#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long;
using P = pair<int, int>;
using lP = pair<ll, ll>;
using fP = pair<double, double>;

map<int, int>mp;
void prime_factor(int n) {
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n != 1)mp[n]++;
}
int main() {
    int n;
    cin >> n;
    rep(i, n) {
        prime_factor(i + 1);
    }
    int a75 = 0, a25 = 0, a15 = 0, a5 = 0, a3 = 0;
    for (auto x : mp) {
        if (x.second >= 74)a75++;
        if (x.second >= 24)a25++;
        if (x.second >= 14)a15++;
        if (x.second >= 4)a5++;
        if (x.second >= 2)a3++;
    }
    int ans = 0;
    ans += a75;
    ans += a25 * (a3-1);
    ans += a15 * (a5-1);
    ans += a5 * (a5-1)/2 * (a3-2);
    cout << ans << endl;
    return 0;
}