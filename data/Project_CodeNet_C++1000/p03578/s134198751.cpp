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
    ll n;
    cin >> n;
    vector<ll> D(n);
    rep(i, n) cin >> D[i];
    ll m;
    cin >> m;
    vector<ll> T(m);
    rep(i, m) cin >> T[i];

    sort(D.begin(), D.end());
    sort(T.begin(), T.end());
    ll j = 0; //Dの参照位置
    rep(i, m)
    {
        if (T[i] == D[j])
        {
            j++;
            continue;
        }
        else
        {
            while (1)
            {
                if (j == n)
                {
                    cout << "NO" << endl;
                    return 0;
                }
                if (T[i] == D[j])
                {
                    j++;
                    break;
                }
                else
                {
                    j++;
                }
            }
        }
    }
    cout << "YES" << endl;
}