#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, Z, W;
    cin >> N >> Z >> W;

    vector<long long> a(N);
    for (long long &elem : a)
    {
        cin >> elem;
    }

    if (N == 1)
    {
        cout << abs(a.front() - W) << endl;
    }
    else
    {
        cout << max(abs(a.back() - W), abs(a[N - 2] - a.back())) << endl;
    }
}
