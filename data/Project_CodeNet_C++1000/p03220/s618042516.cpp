#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
    int n;
    double t, a;
    cin >> n >> t >> a;
    vector<pair<double, int>> means(n);
    rep(i, n) {
        double h; cin >> h;
        means[i].first = abs(t-0.006*h - a);
        means[i].second = i;
        means[i].second++; 
    }
    sort(means.begin(), means.end());
    cout << means[0].second << endl;
    return 0;
}