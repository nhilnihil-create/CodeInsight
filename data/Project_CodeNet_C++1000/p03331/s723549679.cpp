#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int total = 0;

    while (n)
    {
        total += n % 10;
        n = n / 10;
    }

    if (total == 1)
    {
        cout << 10 << endl;
    }
    else
    {
        cout << total << endl;
    }
    return 0;
}