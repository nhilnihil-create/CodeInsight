#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    cout << fmin(n * a, b);
    return 0;
}
