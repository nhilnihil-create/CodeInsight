#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int keta(int n)
{
    int cnt = 0;
    while (n)
    {
        n /= 10;
        cnt++;
    }
    return cnt;
}

int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    int ans = 0;

    for (int i = min(a, b); i >= 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            ans++;
        }
        if (ans == k)
        {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
