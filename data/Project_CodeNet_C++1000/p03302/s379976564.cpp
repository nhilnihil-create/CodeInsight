#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    if (a + b == 15) return !(cout << "+" << endl);
    if (a * b == 15) return !(cout << "*" << endl);
    cout << "x" << endl;
    return 0;
}
