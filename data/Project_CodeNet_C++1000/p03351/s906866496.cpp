#include <iostream>
using namespace std;

inline short int dist(short int a, short int b) {
    return a > b ? a - b : b - a;
}

int main() {
    short int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (dist(a, b) <= d && dist(b, c) <= d) cout << "Yes\n";
    else if (dist(a, c) <= d) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}