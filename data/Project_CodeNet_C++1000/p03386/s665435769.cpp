#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll a, b, k;
        cin >> a >> b >> k;

        ll total = b - a + 1;
        for (int i = 0; i < total; ++i) {


                if (i < k || i >= total-k) {
                        cout << a+i << endl;
                }



        }
}
