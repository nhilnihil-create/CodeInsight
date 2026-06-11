#include <bits/stdc++.h>
#include <numeric>
#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define SORT_INV(c) sort((c).begin(), (c).end(), greater<int>())

#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false
#define LL long long
#define Dev 1000000007

// sort(a.begin(), a.end(), std::greater<int>());
using namespace std;

int main()
{
    long long int n, p;
    cin >> n >> p;
    long long int fixP = p;
    map<long long int, long long int> mp;
    int i = 2;
    if (n == 1)
    {
        cout << p << endl;
        return 0;
    }
    while (true)
    {
        if (p % i == 0)
        {
            mp[i]++;
            p = p / i;
        }
        else
        {
            i++;
        }
        if (p == 1 || sqrt(fixP + 100) < i)
            break;
    }
    long long int ans = 1;
    for (auto x : mp)
    {
        ans = ans * pow(x.first, x.second / n);
    }
    cout << ans << endl;
}
