#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int d = b - a;

    if (d % 2 == 1) {
        cout << "Borys" << endl;
    } else {
        cout << "Alice" << endl;
    }
}