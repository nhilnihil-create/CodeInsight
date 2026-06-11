#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N;
    cin >> N;
    vector<long long> a(N);
    vector<long long> b(N);
    vector<long long> c(N);
    for (long long i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    for (long long i = 0; i < N; i++)
    {
        cin >> b[i];
    }
    for (long long i = 0; i < N; i++)
    {
        cin >> c[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    long long ans = 0;
    for (long long i = 0; i < N; i++)
    {
        long long anum = 0;
        long long cnum = 0;
        long long min = -1;
        long long max = N;
        while(1)
        {
            if (max - min == 1)
            {
                anum = min + 1;
                break;
            }
            if (a[(min + max) / 2] < b[i])
            {
                min = (min + max) / 2;
            }
            else
            {
                max = (min + max) / 2;
            }
        }
        min = -1;
        max = N;
        while(1)
        {
            if (max - min == 1)
            {
                cnum = N - max;
                break;
            }
            if (c[(min + max) / 2] <= b[i])
            {
                min = (min + max) / 2;
            }
            else
            {
                max = (min + max) / 2;
            }
        }
        ans += anum * cnum;
    }
    cout << ans << endl;
}