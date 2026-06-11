#include <iostream>
#include <complex>
using namespace std;
int main(void) {
int a, b, c, d, sa, ta, ru;

cin >> a;
cin >> b;
cin >> c;
cin >> d;
sa = std::abs(a-b);
ta = std::abs(b-c);
ru = std::abs(a-c);
if ( sa <= d && ta <= d ) {
    cout << "Yes" << endl;
} else if ( ru <= d) {
    cout << "Yes" << endl;
} else {
    cout << "No" << endl;
}

return 0;
}