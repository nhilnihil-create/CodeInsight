#include <iostream>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    long long a = n / k;
    long long c = a * a * a;
    if (k % 2 == 1)
        cout << c << endl;
    else
    {
        long long b = n / (k / 2) - a, d = b * b * b;
        cout << c + d << endl;
    }
    return 0;
}
