#include <iostream>
using namespace std;
int main() {
    char X, Y; cin >> X >> Y;
    if (X < Y) printf("%c\n", '<');
    else if (X == Y) printf("%c\n", '=');
    else printf("%c\n", '>');
}