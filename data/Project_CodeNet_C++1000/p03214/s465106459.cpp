#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1000;
const int INF = 1e9;
int a[N];
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int minn = INF;
    ;
    for (int i = 0; i < n; i++)
    {
        minn = min(minn, abs(a[i] * n - sum));
    }
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i] * n - sum) == minn)
        {
            cout << i;
            return 0;
        }
    }
}