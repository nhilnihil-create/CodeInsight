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
typedef pair<int, int> pair;

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n+1);
    rep(i, m) {
        int a;
        cin >> a;
        c[a] = 1;
    }

    int ans1 = 0, ans2 = 0;

    rep(i, x) ans1 += c[i];
    for (int i = x; i < n; i++) ans2 += c[i];

    int ans = min(ans1, ans2);

    cout << ans << endl;

    return 0;
}