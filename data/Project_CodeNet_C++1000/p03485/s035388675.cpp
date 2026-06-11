#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    double c = (a + b) * 0.5;
    int ans = static_cast<int>(round(c));
    cout << ans << endl;
}
