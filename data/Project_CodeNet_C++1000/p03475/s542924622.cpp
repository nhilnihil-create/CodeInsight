#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstring>

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using PP = pair<ll, pair<ll,ll>>;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

ll n, t;
ll c[500], s[500], f[500];

int main() {
    cin >> n;
    rep(i,n-1) cin >> c[i] >> s[i] >> f[i];
    rep(i,n-1){
        t = s[i] + c[i];
        for (ll j = i+1; j < n-1; j++){
            if (t < s[j]) t = s[j];
            else {
                //次の出発まで待つ
                if (t%f[j]!=0) t += f[j] - t%f[j];
            }
            t += c[j];
        }
        cout << t << endl;
    }
    cout << "0" << endl;
    return 0;
}