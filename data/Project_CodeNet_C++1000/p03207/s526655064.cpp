#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, maxInd = 0, max = 0, res = 0;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
        if(v[i] > max)
        {
            max = v[i];
            maxInd = i;
        }
    }

    for(int i = 0; i < n; ++i)
    {
        res += i != maxInd ? v[i] : v[i] / 2;
    }

    cout << res << "\n";
    return 0;
}