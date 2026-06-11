#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;

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

// 数値を受け取り素因数分解の結果を返す
// 計算量はおおよそO(√N)
// 形式：12 -> [[2, 2], [3, 1]]
map<int, int> factorization(ll num)
{
    map<int, int> mp;

    int tmp = num;
    for (int i = 2; i * i <= num; i++)
    {
        while (tmp % i == 0)
        {
            mp[i]++;
            tmp /= i;
        }
    }
    if (tmp != 1)
    {
        mp[tmp]++;
    }

    return mp;
}

ll comb(int n, int r)
{
    if (n < r)
        return 0;
    ll bunshi = 1;
    ll bunbo = 1;
    for (int i = 1; i <= r; ++i)
    {
        bunshi *= (n - i + 1);
        bunbo *= i;
    }
    return bunshi / bunbo;
}

int main()
{
    int n;
    cin >> n;

    vector<int> cnts(n + 1, 1);
    int three = 0;
    int five = 0;
    int fifty = 0;
    int twentyFive = 0;
    int seventyFive = 0;

    for (int i = 2; i <= n; ++i)
    {
        auto fac = factorization(i);
        for (auto f : fac)
        {
            if (cnts[f.first] < 3 && cnts[f.first] + f.second >= 3)
                ++three;
            if (cnts[f.first] < 5 && cnts[f.first] + f.second >= 5)
                ++five;
            if (cnts[f.first] < 15 && cnts[f.first] + f.second >= 15)
                ++fifty;
            if (cnts[f.first] < 25 && cnts[f.first] + f.second >= 25)
                ++twentyFive;
            if (cnts[f.first] < 75 && cnts[f.first] + f.second >= 75)
                ++seventyFive;
            cnts[f.first] += f.second;
        }
    }
    int ans = 0;
    // 5 * 5 * 3
    ans += comb(five, 2) * (three - 2);
    ans += fifty * (five - 1);
    ans += twentyFive * (three - 1);
    ans += seventyFive;
    cout << ans << endl;
    return 0;
}
