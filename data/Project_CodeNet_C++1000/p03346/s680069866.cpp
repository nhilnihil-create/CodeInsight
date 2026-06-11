#include <bits//stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
int main() {
    int n;cin >> n; vector<int> p(n+1), v(n+1); rep(i, n) cin >> p[i];
    rep(i, n) v[p[i]] = 1 + v[p[i] - 1];
    cout << n - *max_element(v.begin(),v.end()) << endl;
}