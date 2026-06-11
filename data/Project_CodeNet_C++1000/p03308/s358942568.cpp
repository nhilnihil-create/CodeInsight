#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    int x;
    int maxn = -1;
    int minn = 1000000010;
    rep(i, n) {
        cin >> x;
        maxn = max(maxn, x);
        minn = min(minn, x);
    }

    cout << maxn - minn << endl;



    return 0;
}