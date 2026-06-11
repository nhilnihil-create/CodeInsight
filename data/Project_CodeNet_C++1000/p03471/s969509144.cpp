#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int n, y;
    cin >> n >> y;

    int a, b, c;
    rep(i, y / 10000 + 1)
    {
        rep(j, y / 5000 + 1)
        {
            int num = y / 1000 - 10 * i - 5 * j;
            if (0 <= num && num <= y / 1000 && i + j + num == n)
            {
                printf("%d %d %d\n", i, j, num);
                return 0;
            }
        }
    }

    printf("-1 -1 -1\n");
    return 0;
}
