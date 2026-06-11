#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, i;
    cin >> n >> i;
    if(n - i >= 0)
        cout << n - i + 1;
    else
        cout << 0;
    return 0;
}