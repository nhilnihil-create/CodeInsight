#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int dif = b - a;
    int sum = 0;
    for (int i = 1; i <= dif; i++)
    {
        sum += i;
    }

    // cout << sum << endl;
    cout << sum - b << endl;
    return 0;
}