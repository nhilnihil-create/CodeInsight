#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxN = 3005;
const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
    int n;
    string s;

    cin >> n >> s;

    vector<int> f(maxN);
    f[0] = 1;
    for(int i = 1; i <= n - 1; ++i)
    {
        vector<int> f1(maxN);
        int tmp = 0;
        if(s[i - 1] == '<')
            for(int j = 0; j < i; ++j)
            {
                tmp = (tmp + f[j]) % mod;
                f1[j + 1] = tmp;
            }
        else
            for(int j = i - 1; j >= 0; --j)
            {
                tmp = (tmp + f[j]) % mod;
                f1[j] = tmp;
            }
        f = f1;
    }

    int res = 0;
    for(int i = 0; i < n; ++i)
        res = (res + f[i]) % mod;

    cout << res;
}
