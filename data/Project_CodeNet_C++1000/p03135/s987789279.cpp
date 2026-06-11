#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double t, x;
    cin >> t >> x;
    cout << setprecision(11) << t / x;
    return 0;
}