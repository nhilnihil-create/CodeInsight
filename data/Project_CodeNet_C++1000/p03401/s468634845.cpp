#include <bits/stdc++.h>
using namespace std;

int main()
{

        int n = 0;

        cin >> n;

        int a[n+2];

        for (int i = 0; i < n+2; ++i) {
                if (i == 0 || i == n + 1) {
                        a[i] = 0;
                }
                else {
                        cin >> a[i];
                }
        }

        int base = 0;
        for (int i = 0; i < n+1; ++i) {

                base += abs(a[i+1] - a[i]);

        }

        int minus = 0;
        int plus = 0;
        for (int i = 1; i < n+1; ++i) {

                minus = abs(a[i] - a[i-1]) + abs(a[i+1] - a[i]);
                plus = abs(a[i+1] - a[i-1]);

                cout << base - minus + plus << endl;

        }


}
