#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;
#define prev prev55

long long n, t[50000], v[50000];
long long scale[50000];

int main()
{
    fill(scale, scale + 50000, 1000000000000);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) t[i] += t[i], v[i] += v[i];
    int l = 0;
    for (int i = 0; i <= 40000; i++) scale[i] = min(scale[i], (long long)i);
    for (int j = 0; j < n; j++)
    {
        int r = l + t[j];
        for (int i = l; i >= 0; i--)
        {
            scale[i] = min(scale[i], l - i + v[j]);
        }
        for (int i = l; i <= r; i++) scale[i] = min(scale[i], v[j]);
        for (int i = r; i <= 40000; i++)
        {
            scale[i] = min(scale[i], i - r + v[j]);
        }
        l = r;
    }
    for (int i = l; i >= 0; i--) scale[i] = min(scale[i], (long long)l - i);
    for (int i = l; i <= 40000; i++) scale[i] = 0;
    long long summ = 0;
    for (int i = 0; i <= 40000; i++)
    {
        summ += scale[i];
    }
    printf("%.9f", summ / 4.0);
}
