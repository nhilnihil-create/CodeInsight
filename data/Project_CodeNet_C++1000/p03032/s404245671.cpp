#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n], left[n], right[n];
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i <= min(n, k); i++)
    {
        for(int j = 0; j <= min(n, k) - i; j++)
        {
            int sub[n];
            long long total = 0;
            for(int l = 0; l < i; l++)
            {
                sub[l] = a[l];
                total += a[l];
            }
            for(int l = 0; l < j; l++)
            {
                sub[l + i] = a[n - l - 1];
                total += a[n - l - 1];
            }
            sort(sub, sub + i + j);
            for(int l = 0; l < min(i + j, k - i - j); l++)
            {
                if(sub[l] < 0)
                {
                    total -= sub[l];
                }
            }
            ans = max(ans, total);
        }
    }
    cout << ans << endl;
    return 0;
}