#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, Y;
void func()
{
    cin >> N >> Y;
    rep(i, 0, N + 1)
    {
        rep(j, 0, N + 1 - i)
        {
            if (10000 * i + 5000 * j + 1000 * (N - i - j) == Y)
            {
                printf("%d %d %d\n", i, j, N - i - j);
                return;
            }
        }
    }
    printf("-1 -1 -1\n");
}
int main()
{
    func();
}