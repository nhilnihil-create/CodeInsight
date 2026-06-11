#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main()
{
    vector<int> n(3);
    rep (i, 3)
        cin >> n[i];

    sort(n.begin(), n.end());
    cout << n[2] * 10 + n[1] + n[0] << endl;
    return 0;
}