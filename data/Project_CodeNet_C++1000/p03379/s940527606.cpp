#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, M;
void func()
{
    cin >> N;
    int x[N], y[N];
    rep(i, 0, N) cin >> x[i];
    memcpy(y, x, sizeof(int) * N);
    sort(&y[0], &y[N]);
    rep(i, 0, N)
    {
        if (x[i] >= y[N / 2])
            printf("%d\n", y[N / 2 - 1]);
        else
        {
            printf("%d\n", y[N / 2]);
        }
    }
}
int main()
{
    func();
}