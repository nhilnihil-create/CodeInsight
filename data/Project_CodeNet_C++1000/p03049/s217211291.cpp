#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
    ll n;
    cin >> n;
    ll xa = 0;
    ll bx = 0;
    ll bxa = 0;
    ll ab = 0;
    rep(i, n)
    {
        string s;
        cin >> s;
        ll l = s.length();
        if (s[0] == 'B' && s[l - 1] == 'A')
            bxa++;
        else if (s[l - 1] == 'A')
            xa++;
        else if (s[0] == 'B')
            bx++;
        for (int j = 0; j <= l - 2; j++)
        {
            string tmp;
            tmp = s.substr(j, 2);
            if (tmp == "AB")
                ab++;
        }
    }
    if (xa + bx == 0&&bxa!=0)
        cout << ab + bxa - 1 << endl;
    else
        cout << ab + min(xa, bx)+bxa << endl;
}