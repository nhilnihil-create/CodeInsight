#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i += 2)
    {
        int cnt = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                cnt++;
            }
        }
        if (cnt == 8)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}