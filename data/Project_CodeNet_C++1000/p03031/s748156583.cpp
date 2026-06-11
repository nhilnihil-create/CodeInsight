#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector <int>;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define REP(i,n) for(int i=0;i<n;i++)

int main () {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    int k[m];
    int s[m];
    REP(i, m) {
        cin >> k[i];
        s[i] = 0;
        REP(j, k[i]) {
            int tmp; cin >> tmp;
            s[i] |= (1 << (tmp-1));
        }
    }
    int p[m];
    REP(i, m) {
        cin >> p[i];
    }

    int cnt = 0;
    REP(bit, (1 << n)) {
        bool flag = true;
        REP(i, m) {
            if (__builtin_popcount(bit & s[i])%2 != p[i]) {
                flag = false;
                break;
            }
        }
        if (flag) cnt++;
    }
    cout << cnt << "\n";
}