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
const int inf = 1000000000; //10^9

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep (i, n) cin >> a[i];
    
    int ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i] <= x) {
            ans++;
            x -= a[i];
        }
        else continue;
    }
    if (x) ans = min(ans, n - 1);
    cout << ans << endl;

    return 0;
}