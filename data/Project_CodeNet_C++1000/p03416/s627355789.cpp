#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    int n10k, nk, nc, nd, n1, counter = 0;

    cin >> a >> b;
    for (int n = a; n< b + 1; n++)
    {
        n10k = n / 10000;
        nk = (n - n10k * 10000) / 1000;
        nc = (n - n10k * 10000 - nk * 1000) / 100;
        nd = (n - n10k * 10000 - nk * 1000 - nc * 100) / 10;
        n1 = (n - n10k * 10000 - nk * 1000 - nc * 100 - nd * 10);

        if ((n10k == n1) && (nk == nd))
        {
            counter++;
        }
    }    
    cout << counter;

    return 0;
}