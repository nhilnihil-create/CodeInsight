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
    int n; 
    cin >> n;
    vector<double> x(n);
    vector<string> u(n);
    rep(i, n) {
        cin >> x[i] >> u[i];
    }
    rep(i, n) {
        if(u[i] == "BTC") {
            x[i] *= 380000;
        }
    }
    double ans = 0;
    rep(i, n) {
        ans += x[i];
    }
    cout << ans << endl;
}
