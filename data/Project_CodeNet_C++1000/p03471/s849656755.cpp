#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    int n,y;
    int a,b,c;

    cin >> n >> y;

    a = b = c = -1;
    for (int i = 0;i <= n;++i)
        for (int j = 0;j <= n-i;++j) {
            int k = n - i - j;
            if (k >= 0 && k <= n)
                if (10000 * i + 5000 * j + 1000 * k == y) {
                    a = i;
                    b = j;
                    c = k;
                    goto OWARI;
                }
        }

 OWARI:
    cout << a << " " << b << " " << c << endl;

    return(0);
}