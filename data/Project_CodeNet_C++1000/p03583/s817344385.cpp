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
    for (int a = 1; a <= 3500; a++)
    {
        for (int b = 1; b <= 3500; b++)
        {
            if (4 * a * b - n * b - n * a == 0)
                continue;
            int c = (n * a * b) / (4 * a * b - n * b - n * a);
            if ((n * a * b) % (4 * a * b - n * b - n * a) == 0 && c > 0&&c<=3500)
            {
                cout << a << " " << b << " " << c << endl;
                return 0;
            }
        }
    }
}