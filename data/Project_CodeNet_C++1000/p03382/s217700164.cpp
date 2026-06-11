#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int64_t a[100'000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, [](const auto &lh, const auto &rh) {
        return lh > rh;
    });
    int64_t amax = a[0];

    int yIdx = 0;
    for (int i = 1; i < n; i++)
    {
        if (abs(amax - 2 * a[yIdx]) >= abs(amax - 2 * a[i]))
        {
            yIdx = i;
        }
    }

    cout << amax << " " << a[yIdx] << endl;
    return 0;
}