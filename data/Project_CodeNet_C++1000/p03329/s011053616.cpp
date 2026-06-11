#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;
const int MOD = 1'000'000'007;

template <typename T>
void print(const T &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

const int MAX = 100010;

int n;
ll dp[MAX];

int main()
{
    int n;
    cin >> n;
    vector<int> coin;
    int six = 6;
    while (six <= n)
    {
        coin.push_back(six);
        six *= 6;
    }
    int nine = 9;
    while (nine <= n)
    {
        coin.push_back(nine);
        nine *= 9;
    }
    sort(coin.begin(), coin.end());
    for (int i = 0; i <= n; i++)
    {
        dp[i] = i;
    }
    for (int c : coin)
    {
        for (int i = 0; i <= n; i++)
        {
            if (i >= c)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}