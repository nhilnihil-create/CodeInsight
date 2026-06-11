#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <string>
#include <string.h>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define For(i, s, n) for (int i = s; i <= n; ++i)
#define ForD(i, s, n) for (int i = s; i >= n; --i)
#define ForV(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define ms(a, x) memset(a, x, sizeof(a))
#define sz(a) ((int)(a).size())
#define ii pair<int, int>
#define fi first
#define se second

typedef long long ll;

const int N = 1e5 + 5, LIMIT = 1e9 + 7;

map <string, int> mp;
string s;
int n;

void Read()
{
   //freopen("SC.INP", "r", stdin);
   //freopen("SC.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
}

void Process1()
{
    For (i, 0, (1 << n) - 1)
    {
        string r = "", b = "";
        ForV (j, n)
        {
            if (i >> j & 1)
            {
                r = r + s[j];
            }
            else
            {
                b = b + s[j];
            }
        }
        ++mp[r + "." + b];
    }
}

void Process2()
{
    ll ans = 0;
    For (i, 0, (1 << n) - 1)
    {
        string r = "", b = "";
        ForV (j, n)
        {
            if (i >> j & 1)
            {
                r = s[n + j] + r;
            }
            else
            {
                b = s[n + j] + b;
            }
        }
        ans += mp[b + "." + r];
    }
    cout << ans;
}

int main()
{
    Read();
    Process1();
    Process2();
    return 0;
}
