#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    double b, ave, sum = 0, min = 1000000;
    cin >> N;
    int k = N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++)
    {
        sum += a[i];
    }
    ave = sum / N;
    for (int i = N - 1; i >= 0; i--)
    {
        b = ave - a[i];
        if (b < 0)
        {
            b *= (-1);
        }
        if (b <= min && i < k)
        {

            min = b;
            k = i;
        }
    }
    cout << k << endl;
}