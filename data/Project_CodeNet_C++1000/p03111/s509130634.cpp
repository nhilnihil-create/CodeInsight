#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
    int N, A, B, C; cin >> N >> A >> B >> C;
    if(A > B) swap(A, B);
    if(B > C) swap(B, C);
    if(A > B) swap(A, B);
    int l[N], a[N];
    for(int i = 0; i < N; i++) {
        cin >> l[i];
        a[i] = i;
    }

    int ans = INF, tmp;
    do
    {
        for (int i = 0; i < N; i++)
        {
            int x = 0;
            for (int m = 0; m <= i; m++)
            {
                x += l[a[m]];
            }
            for (int j = i+1; j < N; j++)
            {
                int y = 0;
                for (int m = i+1; m <= j; m++)
                {
                    y += l[a[m]];
                }
                for (int k = j+1; k < N; k++)
                {
                    int z = 0;
                    for (int m = j+1; m <= k; m++)
                    {
                        z += l[a[m]];
                    }
                    int xc = x, yc = y, zc = z;
                    if(xc > yc) swap(xc, yc);
                    if(yc > zc) swap(yc, zc);
                    if(xc > yc) swap(xc, yc);
                    tmp = abs(A - xc) + abs(B - yc) + abs(C - zc);
                    ans = min(ans, tmp + 10 * (k - 2));
                }
            }
        }
    } while (next_permutation(a, a + N));

    cout << ans << endl;
    return 0;
}