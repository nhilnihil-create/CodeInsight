#include <iostream>
using namespace std;
int main() {
    int a, b; cin >> a >> b;
    if (a + b == 15) printf("%c\n", '+');
    else if (a * b == 15) printf("%c\n", '*');
    else printf("%c\n", 'x');
}