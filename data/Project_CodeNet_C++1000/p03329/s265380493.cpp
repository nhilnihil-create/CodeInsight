#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()
const ll mod = 998244353;
const ll n_max = 10e5;
int main()
{
    int n;
    cin >> n;
    v<int> dp(n + 1, n_max);
    v<int> num;
    dp[0] = 0;

    num.push_back(1);

    int six = 6, nine = 9;
    while (true)
    {
        num.push_back(six);
        six *= 6;
        if (six > n)
            break;
    }

    while (true)
    {
        num.push_back(nine);
        nine *= 9;
        if (nine > n)
            break;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i + 1 - num[j] >= 0)
            {
                dp[i + 1] = min(dp[i + 1], dp[i + 1 - num[j]] + 1);
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}