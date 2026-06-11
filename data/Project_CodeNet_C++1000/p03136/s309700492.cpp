#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n;
    cin >> n;
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    sort(all(l));

    int cnt = 0;
    rep(i, n) cnt += l[i];

    cout << ((cnt - l[n - 1] > l[n - 1]) ? "Yes" : "No") << '\n';
    return 0;
}
