#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int a[10];

int main()
{
    rep(i, 4) {
        int n;
        cin >> n;
        a[n]++;
    }
    if(a[1] == 1 && a[4] == 1 && a[7] == 1 && a[9] == 1) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}