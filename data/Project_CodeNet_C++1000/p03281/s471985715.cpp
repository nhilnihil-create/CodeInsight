#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N;
    cin >> N;
    long long ans = 0;
    for (long long i = 1; i <= N; i++)
    {
        if (i % 2 == 1)
        {
            long long count = 0;
            for (long long j = 1; j < pow(i, 0.5); j++)
            {
                if (j % 2 == 1 && i % j == 0)
                {
                    count++;
                }
            }
            if (count == 4)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}