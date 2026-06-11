#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
 
int main(void) {
    double t, x;
    cin >> t >> x;
    cout << fixed << setprecision(10) << t  / x << endl;
    return 0;
}