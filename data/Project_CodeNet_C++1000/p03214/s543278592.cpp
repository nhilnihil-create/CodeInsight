#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int sum = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }

    double ave = (double)sum/n;
    vector<pair<double, int>> p(n);
    rep(i, n) {
        p[i] = make_pair(abs(a[i] - ave), i);
    }
    sort(p.begin(), p.end());

    cout << p[0].second << endl;
    return 0;
}