/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 2002;
const int S_MAX = 4000000;

int n;

int a[N_MAX];

bitset <S_MAX> dp;

int sum;

bitset <S_MAX> aux;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        sum += a[i];
    dp[0] = true;
    for(int i = 1; i <= n; i++)
    {
        aux = dp;
        aux <<= a[i];
        dp |= aux;
    }
    for(int j = (sum + 1) / 2; j <= S_MAX; j++)
        if(dp[j] == true)
        {
            cout << j << "\n";
            return 0;
        }
    return 0;
}
