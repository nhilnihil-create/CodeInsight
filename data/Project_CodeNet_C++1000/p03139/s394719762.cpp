#include <iostream>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    cout << (a > b ? b : a) << ' ' << (a + b > n ? a+b-n : 0) << endl;
}