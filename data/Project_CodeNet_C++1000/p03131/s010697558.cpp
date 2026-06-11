#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll k, a, b;
    cin >> k >> a >> b;
    ll bis = 1, en = 0;
    if (a + 1 < b)
    {
        bool tata = false;
        rep(i, k - 1)
        {
            if (!tata)
            {
                if (bis >= a)
                {
                    en++;
                    bis -= a;
                    tata = true;
                }
                else
                    bis++;
            }
            else
            {
                if (en == 0)
                {
                    bis -= a;
                    en++;
                }
                else
                {
                    en--;
                    bis += b;
                }
            }
        }
        if (en == 0)
            bis++;
        else
            bis += b;
    }
    else
    {
        bis = bis + k;
    }

    cout << bis << endl;
}