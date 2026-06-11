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
    int n, t, a;
    cin >> n >> t >>a;
    int ans = 0;
    int min = 1000000;
    rep(i,n) {
        int x;
        cin >> x;
        int d = abs((t * 1000 - x * 6) - a * 1000);
        if (min > d) {
            min = d;
            ans = i + 1;
        }
    }
    cout << ans << endl;
} 