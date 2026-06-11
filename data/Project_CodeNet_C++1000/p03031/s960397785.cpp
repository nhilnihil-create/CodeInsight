#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define downque(que) priority_queue<ll> que;
#define upque(que) priority_queue<ll, vector<int>, greater<int>> que;
typedef long long ll;
typedef vector<vector<int>> Matrix;
const int MOD = 1e9 + 7;

void all_bit_search(int n, int m, vector<int> p, vector<int> s, int *ans)
{
    int flag;

    for (int bit = 0; bit < (1 << n); ++bit)
    { //スイッチのON・OFFで全探索

        flag = 1;
        REP(i, m)
        {
            //cout << bit << "and" << s[i] <<" = " << __builtin_popcount(bit & s[i])<<" p="<< p[i]<<endl;
            if (__builtin_popcount(bit & s[i]) % 2 != p[i])
                flag = 0;
        }
        if (flag)
            *ans += 1;
    }
}

int main(void)
{
    int n, m, k, tmp, ans = 0;
    cin >> n >> m;
    vector<int> p(m);
    vector<int> s(m, 0);

    REP(i, m)
    {
        cin >> k;
        REP(j, k)
        {
            cin >> tmp;
            s[i] |= (1 << (tmp - 1));
        }
    }

    REP(i, m)
    {
        cin >> tmp;
        p[i] = tmp;
    }

    all_bit_search(n, m, p, s, &ans);

    cout << ans << endl;
    return 0;
}
