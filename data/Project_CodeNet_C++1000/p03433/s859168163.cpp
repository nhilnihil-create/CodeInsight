#include <iostream>
#include <vector>
#include <string>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<unsigned long long int>;

int main(void) {
    Int n, a;
    cin >> n >> a;
    n -= 500 * (n / 500);
    if (n <= a) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
