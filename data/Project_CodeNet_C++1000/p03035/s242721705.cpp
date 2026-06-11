#include <iostream>
using namespace std;
int main() {
    int A, B; cin >> A >> B;
    if (A >= 13) printf("%d\n", B);
    else if (A >= 6 && A <= 12) printf("%d\n", B / 2);
    else printf("%d\n", 0);
}