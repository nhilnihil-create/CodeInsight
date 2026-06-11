/*
    Problem 2
    https://atcoder.jp/contests/abc106/tasks/abc106_b
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <list>
#include <set>
#include <stack>
#include <cctype>
#include <cmath>
#include <bitset>

using namespace std;
/* typedef */
typedef long long ll;
/* constant */
/* global variables */
/* function */
int cntDvisor(int x) {
    if (x <= 1) return 1;
    int cnt = 0;
    for (int i = 1; i*i <= x; i++) {
        if (x % i == 0) {
            cnt++;
            if (i * i != x) cnt++;
        }
    }
    return cnt;
}
/* main */
int main(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i += 2) {
        if (cntDvisor(i) == 8) ans++;
    }
    cout << ans << '\n';
}
