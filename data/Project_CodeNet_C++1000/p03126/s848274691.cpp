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
    int n, m;
    cin >> n >> m;
    vector<int> e(m);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            e[a-1]++;
        }
    }
    int ans = 0;
    rep(i, m) {
        if (e[i] == n) ans++;
    }
    cout << ans << endl;
} 