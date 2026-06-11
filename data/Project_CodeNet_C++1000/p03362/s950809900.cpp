#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int N = pow(10, 5);
vector<bool> isp(N + 1, true);
//素数ならtrueを返すライブラリ
void sieve()
{
    isp[0] = false;
    isp[1] = false;
    for (int i = 2; pow(i, 2) <= N; i++)
    {
        if (isp[i])
            for (int j = 2; i * j <= N; j++)
                isp[i * j] = false;
    }
}

int main()
{
    sieve();
    int n;
    cin >> n;

    int cnt = 0, i = 0;
    while (cnt < n)
    {
        i++;
        if (isp[i] && i % 5 == 1)
        {
            cout << i << " ";
            cnt++;
        }
    }

    cout << endl;
}