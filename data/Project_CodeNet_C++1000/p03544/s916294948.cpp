#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i;
    int n; cin >> n;
    int64_t L, L_1=1, L_2=2;

    if (n == 1) cout << 1 << endl;
    else
    {
        for (i=2; i<=n; i++)
        {
            L = L_1 + L_2;
            L_2 = L_1;
            L_1 = L;
        }
        printf("%ld\n", L);
    }
}