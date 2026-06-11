#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    vector<int> x(n);
    rep (i, n)
        cin >> x.at(i);

    sort(x.begin(), x.end(), greater<int>());

    int a = 0, b = 0;
    rep (i, n) {
        if (i % 2 == 0)
            a += x.at(i);
        else
            b += x.at(i);
    }

    cout << (a - b) << endl;
}
