#include <bitset>
#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    bitset<4000000> b = 1;
    int sum = 0;
    while (n--) { int a; cin >> a; b = b | (b << a); sum += a; }
    for (int r = (sum+1)/2; ; r++) if (b.test(r)) { cout << r << endl; break; }
}
