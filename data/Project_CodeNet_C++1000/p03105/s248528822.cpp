#include <iostream>
using namespace std;
int main() {
    int A, B, C; cin >> A >> B >> C;
    if (B / A >= C) printf("%d\n", C);
    else printf("%d\n", B / A);
}