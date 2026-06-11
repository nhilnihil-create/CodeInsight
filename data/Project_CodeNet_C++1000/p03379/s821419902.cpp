#include <bits/stdc++.h>
using namespace std;
#define BE(x) x.begin(), x.end()

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i].first;
        x[i].second = i;
    }
    sort (BE(x));

    vector<pair<int,int>> y(n);
    for (int i = 0; i < n; i++) {
        y[i].first = x[i].second;
        y[i].second = i;
    }
    sort (BE(y));

    for (int i = 0; i < n; i++) {
        if (y[i].second < n/2) cout << x[n/2].first << endl;
        else cout << x[n/2-1].first << endl;
    }
}