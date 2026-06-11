#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int n, d, x;
    cin >> n >> d >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int choco = 0;
    rep(i, n) {
        choco += d / a[i] ;
        if(d%a[i]!=0 ) choco++;
    }

    cout << choco + x << endl;
}