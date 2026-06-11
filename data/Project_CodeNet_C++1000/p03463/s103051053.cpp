#include <iostream>

using namespace std;

int main() {
    size_t n, a, b;
    cin >> n >> a >> b;
    cout << (a % 2 == b % 2 ? "Alice" : "Borys") << endl;
    return EXIT_SUCCESS;
}