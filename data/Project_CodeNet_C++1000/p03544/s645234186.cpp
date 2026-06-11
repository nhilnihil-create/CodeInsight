#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<ll> l(100);
    l[0] = 2; l[1] = 1;
    rep(i, 2, 100) l[i] = l[i-1] + l[i-2];
    cout << l[n] << endl;
    return 0;
}
