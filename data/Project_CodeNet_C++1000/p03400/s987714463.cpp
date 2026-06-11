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
    int n, d, x;
    cin >> n >> d >> x;
    int ans = 0;
    vector<int> a(n);
    rep (i, n) {
        cin >> a[i];
    }

    rep (i, n) {
        ans += (d - 1) / a[i] + 1;
    }

    cout << ans + x << endl;

    return 0;
}