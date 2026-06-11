#include <iostream>
#include <fstream>
using namespace std;
const long long M = 1000000007;
long long n, k, a[105], F[105][100005], S[105][100005];
int main()
{
    //freopen("CANDY.INP", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    F[0][0] = 1;
    for (int i = 0; i <= k; i++) S[0][i] = 1;
    for (int i = 1; i <= n; i++)
        for (int left = 0; left <= k; left++)
        {
                if (left - a[i] - 1 < 0) F[i][left] = S[i - 1][left];
                else F[i][left] = (S[i - 1][left] - S[i - 1][left - a[i] - 1] + M) % M;

                if (left - 1 < 0) S[i][left] = F[i][left];
                else S[i][left] = (S[i][left - 1] + F[i][left]) % M;
        }
    cout << F[n][k];
    return 0;
}
