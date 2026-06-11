#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char x, y;
    cin >> x >> y;
    if (x > y) cout << ">\n";
    else if (x < y) cout << "<\n";
    else cout << "=\n";
    return 0;
}