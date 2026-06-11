#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int A = 0, B = 0;
    rep(i, n) {
        if (i % 2 == 0) A+=a[i];
        else B+=a[i];
    }
    cout << A-B << endl;
    return 0;
}