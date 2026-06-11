#include <iostream>

using namespace std;

#define ull unsigned long long

int main()
{
    ull n;
    cin >> n;

    ull i;
    for (i = 1; i <= n; i++) {
        if (n == i * i) {
            cout << i * i << endl;
            break;
        } else if (n < i * i) {
            cout << (i - 1) * (i - 1) << endl;
            break;
        }
    }
    return 0;
}