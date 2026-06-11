#include <iostream>
using namespace std;
int main() {
    int A, B, C, D; cin >> A >> B >> C >> D;
    printf("%d\n", min(A, B) + min(C, D));
}