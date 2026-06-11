#include <iostream>

using namespace std;

int main()
{
    int n, d, x;
    cin >> n >> d >> x;
    int ans = x;

    int a[101];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j += a[i])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}