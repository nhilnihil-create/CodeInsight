#include <bits//stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
int n;
int main(void) {
    cin >> n; vector<int> p(n+1), tmp(n+1);
    rep(i, n) cin >> p[i];
    rep(i, n) tmp[p[i]] = 1 + tmp[p[i] - 1];
    cout << n - *max_element(ALL(tmp)) << endl;
}