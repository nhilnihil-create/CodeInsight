#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int count(int n)
{
    int cnt = 0;
    while (n / 2)
    {
        cnt++;
        n /= 2;
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(all(a));
    cout << a[n - 1] - a[0] << endl;
    return 0;
}
