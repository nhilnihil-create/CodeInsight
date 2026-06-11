#include <iostream>
using namespace std;
int main() {
    int A, B; cin >> A >> B;
    if (B % A == 0) printf("%d\n", A + B);
    else printf("%d\n", B - A);
}