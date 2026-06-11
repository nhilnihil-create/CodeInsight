#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define Tpair pair <int, int>
using namespace std;

typedef long long ll;
const int   oo = 1e9 + 1;
const int  mod = 1e9 + 7;
const int maxn = 2e5 + 5;

int n, cnt[maxn], f[maxn];
map <int, int> mp;
string s;

void Init()
{
    cin >> s; n = s.length();
    s.insert (0, " ");
    for (int i = 1; i <= n; ++i)
    {
        cnt[i] = cnt[i - 1];
        cnt[i] ^= (1 << (s[i] - 'a'));
    }
}

void Solve()
{
    mp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = i;
        if (mp.count(cnt[i])) f[i] = min (f[i], mp[cnt[i]] + 1);

        for (int j = 0; j < 26; ++j)
        {
            int x = cnt[i] ^ (1 << j);
            if (mp.count(x)) f[i] = min (f[i], mp[x] + 1);
        }
        if (!mp.count(cnt[i])) mp[cnt[i]] = f[i];
        else mp[cnt[i]] = min (mp[cnt[i]], f[i]);

        //cout << f[i] << " " << cnt[i] << endl;
    }
    cout << f[n];
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("D - Yet Another Palindrome Partitioning.inp", "r", stdin);
    //freopen(".out", "w", stdout);

	Init();
	Solve();
}
//Date 29 Month 10 Year 2017


