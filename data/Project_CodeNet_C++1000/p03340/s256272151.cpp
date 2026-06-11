#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vll = vector<long long>;

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];

    long long sum = 0;
    long long x = 0;

    int r = 0;
    for (int i = 0; i < n; i++) {
        while (r < n&&(sum^a[r])==(sum+a[r])){
            sum += a[r];
            r++;
        }

        x += r - i;
        if(r==i)
            r++;
        else{
            sum -= a[i];
        }
    }
    cout << x << endl;
}