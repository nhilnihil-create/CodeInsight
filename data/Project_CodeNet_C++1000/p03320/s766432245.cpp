#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    cin >> K;
    ll current = 0;
    ll plusNum = 1;
    for (int i = 0; i < K; i++)
    {
        ll test1 = current + plusNum;
        ll temp1 = test1;
        ll sum1 = 0;
        while (temp1)
        {
            sum1 += temp1 % 10;
            temp1 /= 10;
        }
        double testS1 = (double)test1 / (double)sum1;
        ll test2 = current + plusNum * 10;
        ll temp2 = test2;
        ll sum2 = 0;
        while (temp2)
        {
            sum2 += temp2 % 10;
            temp2 /= 10;
        }
        double testS2 = (double)test2 / (double)sum2;
        if (testS1 <= testS2)
        {
            current = test1;
        }
        else
        {
            current = test2;
            plusNum *= 10;
        }
        cout << current << "\n";
    }
    cout.flush();
    return 0;
}
