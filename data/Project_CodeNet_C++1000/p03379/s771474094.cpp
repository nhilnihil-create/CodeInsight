#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int n;
// vector<int> x;
// vector<pair<int,int>> y;
// vector<int> b;
int x[200000];
pair<int,int> y[200000];
int b[200000];

int main() {
    cin >> n;
    // x.resize(n);
    // y.resize(n);
    // b.resize(n);
    rep(i, n) {
        cin >> x[i];
        y[i] = make_pair(x[i], i);
    }
    // sort(y.begin(), y.end());
    sort(y, y+n);
    rep(i, n) {
        if (i < n/2) {
            b[y[i].second] = y[n/2].first ;
        } else {
            b[y[i].second] = y[n/2-1].first;
        }
    }
    rep(i, n) {
        cout << b[i] << endl;
    }
}