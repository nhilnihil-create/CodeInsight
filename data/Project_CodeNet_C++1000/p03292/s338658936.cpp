#include <iostream>
using namespace std;
int main() {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    int maxdiff = max(abs(a1-a2), max(abs(a2-a3), abs(a3-a1)));
    cout << abs(a1-a2) + abs(a2-a3) + abs(a3-a1) - maxdiff << endl;
}
