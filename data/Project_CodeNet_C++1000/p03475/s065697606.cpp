#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

//constexpr ll mod = 1000000007;
//constexpr ll INF = mod * mod;
//constexpr double pi = 3.14159265358979;

ll deviding(ll n,ll m) {
    ll ans = n / m;
    if(n % m != 0) ans++;
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> c(n),s(n),f(n);
    rep(i,n-1) {
        cin >> c[i] >> s[i] >> f[i];
    }
    rep(i,n-1) {
        ll counter = 0;
        for(int j = i; j < n-1; j++) {
            if(j == i) {
                counter += c[i] + s[i];
            }
            else {
                int diff = counter - s[j];
                if(diff < 0) diff = 0;
                int C = deviding(diff,f[j]);
                counter = s[j] + C * f[j];
                counter += c[j];
            }
        }
        cout << counter << endl;
        counter = 0;
    }
    cout << 0 << endl;
}