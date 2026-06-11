#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20)
#define int long long
#define double long double
const int INF = 1e18, MOD = 1e9 + 7;

int n, a, b;

signed main() {
    INCANT;
    cin>>n;
    vector<int> v;
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin>>a>>b;
        res -= b;
        v.push_back(a + b);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < (n + 1) / 2; i++) {
        res += v[i * 2];
    }
    cout<<res<<endl;
}