#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;

int main(){
    int n, m, c;
    cin >> n >> m >> c;
    int ans = 0;
    vector<int> b(m);
    rep(i, m) cin >> b[i];
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n){
        rep(j, m) cin >> a[i][j];
    }
    rep(i, n) {
        rep(j, m) a[i][j] = a[i][j] * b[j];
        int w = 0;
        rep(k, m) w += a[i][k];
        w += c;
        if (w > 0) ans++;
    }
    cout << ans << endl;
} 