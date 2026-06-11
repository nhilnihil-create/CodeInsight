#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    long long int t, a, k;

    cin >> t >> a >> k;

    for (int i = 0; i < k; i++) {
        if (i%2 == 0) {
            if (t%2) {
                t--;
            }
            a += (t / 2);
            t /= 2;
        }
        else {
            if (a%2) {
                a--;
            }
            t += (a/2);
            a /= 2;
        }
    }

    cout << t << " " << a << endl;
}
