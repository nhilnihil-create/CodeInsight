#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;

int n;
bool ign[Maxn][Maxn];
vector <ii> res;

int main()
{
    scanf("%d", &n);
    int m = n / 2 * 2;
    int l = 1, r = m;
    while (l < r) {
        ign[l][r] = true;
        l++; r--;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) if (!ign[i][j])
            res.push_back(ii(i, j));
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}
