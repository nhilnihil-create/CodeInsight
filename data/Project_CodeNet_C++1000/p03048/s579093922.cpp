#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int r, g, b, n, i, j, ans;

    scanf("%d%d%d%d", &r, &g, &b, &n);

    ans = 0;
    i = 0;
    while (r * i <= n)
    {
        j = 0;
        while (r * i + g * j <= n)
        {
            if ((n - r * i - g * j) % b == 0)
                ans++;
            j++;
        }
        i++;
    }

    printf("%d\n", ans);

    return 0;
}