#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
ll pow(int n, int e)
{
    ll ans = 1;
    for (int i = 0; i < e; i++)
    {
        ans *= n;
    }
    return ans;
}
ll N;
ll sum = 0;

int main()
{
    cin >> N;
    int keta = 0;
    ll num = N;
    while (num > 0)
    {
        num /= 10;
        keta++;
    }
    ll NN;
    if (N > 8 && N % 10 != 9)
    {
        /* keta-1を一つへらす */
        NN = (N / (pow(10, keta - 1)) - 1) * pow(10, keta - 1);
        /*keta-1まで9で埋める */
        for (int i = 1; i < keta; i++)
        {
            NN += 9 * pow(10, i - 1);
        }
    }
    else
    {
        NN = N;
    }
    while (NN > 0)
    {
        sum += NN % 10;
        NN /= 10;
    }
    cout << sum << endl;

    return 0;
}
