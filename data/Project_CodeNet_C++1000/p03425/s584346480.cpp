#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n;
    cin >> n;
    map<char, int> initial;
    string s;
    rep(i, n)
    {
        cin >> s;
        if (s[0] == 'M' || s[0] == 'A' || s[0] == 'R' || s[0] == 'C' || s[0] == 'H')
        {
            initial[s[0]]++;
        }
    }
    ll cnt = 0;
    char march[5] = {'M', 'A', 'R', 'C', 'H'};
    for (int bit = 0; bit < (1 << 5); bit++)
    {
        if (__builtin_popcount(bit) != 3)
            continue;
        ll mult = 1;
        rep(i, 5)
        {
            if (bit & (1 << i))
                mult *= initial[march[i]];
        }
        cnt += mult;
    }
    cout << cnt << endl;
    return 0;
}