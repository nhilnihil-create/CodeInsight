#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int a[2'000];

int main()
{
    int n, z, w;
    cin >> n >> z >> w;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        cout << abs(w - a[n - 1]) << endl;
        return 0;
    }

    cout << max(abs(w - a[n - 1]), abs(a[n - 2] - a[n - 1])) << endl;
}