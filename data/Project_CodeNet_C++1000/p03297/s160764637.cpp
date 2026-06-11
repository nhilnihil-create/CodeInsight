#include <iostream>
#include <stdint.h>
#include <string>

using namespace::std;

int64_t gcd(int64_t x, int64_t y)
{
        return ((x % y == 0) ? y : gcd(y, x % y));
}

int main()
{
        string yes = "Yes";
        string no = "No";

        int T;
        cin >> T;

        for (int t = 0; t < T; t++)
        {
                int64_t A, B, C, D;
                cin >> A >> B >> C >> D;

                if (D < B)
                {
                        cout << no << endl;
                        continue;
                }

                if (A < B)
                {
                        cout << no << endl;
                        continue;
                }

                if (C >= B)
                {
                        cout << yes << endl;
                        continue;
                }

                int64_t d = gcd(B, D);
                int64_t r = (A - (C + 1)) / d;

                int64_t a = A - r * d;
                if (a >= B)
                        cout << yes << endl;
                else
                        cout << no << endl;
        }

        return 0;
}