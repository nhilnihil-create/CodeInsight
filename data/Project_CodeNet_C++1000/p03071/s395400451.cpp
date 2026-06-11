#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int maxCoin = max(a, b);

    cout << max((maxCoin + (maxCoin - 1)), (a + b)) << endl;

    return 0;
}