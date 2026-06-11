#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> t(n + 1, 0);
    vector<int> x(n + 1, 0);
    vector<int> y(n + 1, 0);
    bool doable = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> x[i] >> y[i];
        int dis = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
        if (dis > (t[i] - t[i - 1]) ||
            dis % 2 != (t[i] - t[i - 1]) % 2)
            doable = 0;
    }

    if (doable)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}