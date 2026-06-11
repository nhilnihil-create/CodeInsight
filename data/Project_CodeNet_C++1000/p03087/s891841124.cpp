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
    int n, q;
    string s;
    cin >> n >> q;
    cin >> s;
    bool is_stt = false;
    vector<int> cnt(n, 0);
    vector<int> out(n + 1, 0);
    rep(i, n)
    {
        if (is_stt)
        {
            if (s[i] == 'C')
            {
                is_stt = false;
                cnt[i]++;
            }
            else if (s[i] != 'A')
            {
                is_stt = false;
            }
        }
        else
        {
            if (s[i] == 'A')
                is_stt = true;
        }
    }
    rep(i, n) out[i + 1] = out[i] + cnt[i];
    int l, r;
    rep(i, q)
    {
        cin >> l >> r;
        cout << out[r] - out[l] << endl;
    }
    return 0;
}