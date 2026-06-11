#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N;
    cin >> N;

    vector<long long> x(N);
    vector<long long> y(N);
    vector<long long> h(N);

    for (long long i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i] >> h[i];
    }

    for (long long X = 0; X <= 100; X++)
    {
        for (long long Y = 0; Y <= 100; Y++)
        {
            long long H = 0;
            long long Hmax = 10000000000;
            for (long long i = 0; i < N; i++)
            {
                if (h[i] != 0)
                {
                    if (H == 0)
                    {
                        H = abs(x[i] - X) + abs(y[i] - Y) + h[i];
                    }
                    else if (H != abs(x[i] - X) + abs(y[i] - Y) + h[i] || Hmax < abs(x[i] - X) + abs(y[i] - Y) + h[i])
                    {
                        break;
                    }
                }
                else
                {
                    if (Hmax > abs(x[i] - X) + abs(y[i] - Y) + h[i])
                    {
                        Hmax = abs(x[i] - X) + abs(y[i] - Y) + h[i];
                    }

                    if (H > Hmax && H != 0)
                    {
                        break;
                    }
                }
                if(i == N - 1)
                {
                    cout << X << " " << Y << " " << H << endl;
                    exit(0);
                }
            }
        }
    }
}