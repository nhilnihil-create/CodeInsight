#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        a[i] = x - i;
    }

    sort(a.begin(), a.end());
    int b = a[(n - 1) / 2];
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += abs(a[i]-b);
    }

    cout << ans << endl;

    return 0;
}