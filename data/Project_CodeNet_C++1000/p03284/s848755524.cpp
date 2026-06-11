#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a,b,m;
    cin >> a >> b;
    m = ceil(a/b) - floor(a/b);
    cout << m;
    return 0;
}
