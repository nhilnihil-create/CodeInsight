#include <iostream>
using namespace std;
int main() {
    int a, b; cin >> a >> b;
    if (b < a) printf("%d\n", a - 1);
    else printf("%d\n", a);
}