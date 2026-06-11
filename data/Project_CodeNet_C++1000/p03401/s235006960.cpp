#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vll a(n);
    rep(i, n) cin >> a[i];

    vll b(n + 1, 0);

    b[0] = abs(a[0] - 0);

    for (int i = 0; i < n - 1; i++) {
        b[i + 1] = abs(a[i + 1] - a[i]);
    }
    b[n] = abs(0 - a[n - 1]);

    ll sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += b[i];
    }

    for (int i = 0; i < n; i++) {
        ll t = sum - (b[i] + b[i + 1]);

        if(i==0){
            t += abs(0 - a[1]);
        }else if(i==n-1){
            t += abs(0 - a[n - 2]);
        }else{
            t += abs(a[i - 1] - a[i + 1]);
        }

        cout << t << endl;
    }
}