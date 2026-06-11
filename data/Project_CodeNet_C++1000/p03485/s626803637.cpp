#include <iostream>
using namespace std;
int main() {
    int a, b; cin >> a >> b;
    if ((a + b) % 2 != 0) printf("%d\n", (a + b) / 2 + 1);
    else printf("%d\n", (a + b) / 2);
}