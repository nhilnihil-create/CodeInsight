#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
void chmax(t &a, u b)
{
    if (a < b)
        a = b;
}
template <class t, class u>
void chmin(t &a, u b)
{
    if (b < a)
        a = b;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a[26] = {0};
    int ans = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        a[s[i] - 'a'] = 1;
        int b[26] = {0};
        for (size_t j = i + 1; j < s.size(); j++)
        {
            b[s[j] - 'a'] = 1;
        }
        int cnt = 0;
        for (size_t j = 0; j < 26; j++)
        {
            if (a[j] == 1 && b[j] == 1)
            {
                cnt++;
            }
        }
        chmax(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}