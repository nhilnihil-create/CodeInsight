#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    int zero = 0, nn= 0;
    rep(i,m) {
        if(a[i]<x) zero++;
        else nn++;
    }
    cout << min(zero, nn) << endl;
    return 0;
}