#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    sort(p.begin(), p.end());
    int sum = 0;
    rep(i, n - 1) {
        sum += p[i];
    }
    sum += p[n - 1] / 2;
    cout << sum << endl;
    return 0;
}