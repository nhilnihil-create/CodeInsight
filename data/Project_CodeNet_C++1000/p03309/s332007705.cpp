#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 10000000000
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        a[i] = a[i] - (i + 1);
    }
    sort(a.begin(), a.end());
    int b1 = a[n / 2];
    int b2  = a[(n - 1) / 2];
    ll tmp1 = 0, tmp2 = 0;
    rep(i,n){
        tmp1 += abs(a[i] - b1);
        tmp2 += abs(a[i] - b2);
    }
    cout << min(tmp1, tmp2) << endl;
    return 0;
}
