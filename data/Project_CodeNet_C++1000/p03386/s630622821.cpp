#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll A, B, K;
        cin >> A >> B >> K;

        ll total = B - A + 1;

        for (int i = 0; i < total; ++i) {

                if (i < K || (total - K) <= i) {

                        cout << A + i << endl;
                }


        }


}
