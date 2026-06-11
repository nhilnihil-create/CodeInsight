#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int ans = a[0] % 2 == 0 ? 2 : 1;
    rep(i, n - 1) ans *= a[i + 1] % 2 == 0 ? 2 : 1; 

    ans = pow(3,n) - ans;
    cout <<ans<<endl;
}