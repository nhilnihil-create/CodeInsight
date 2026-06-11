/*
    Problem 2
    https://atcoder.jp/contests/abc106/tasks/abc106_b
*/
#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
int cntDivisor(int x) {
    int ret = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            ret++;
            if (i * i != x) ret++;
        }
    }
    return ret;
}
/* main */
int main(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 105; i <= n; i+=2) ans += (cntDivisor(i) == 8);
    cout << ans << '\n';
}
