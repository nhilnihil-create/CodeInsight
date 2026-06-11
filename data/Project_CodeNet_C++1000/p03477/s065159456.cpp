#include <iostream>
using namespace std;
int main() {
    int A, B, C, D; cin >> A >> B >> C >> D;
    if (A + B < C + D) printf("%s\n", "Right");
    else if (A + B == C + D) printf("%s\n", "Balanced");
    else printf("%s\n", "Left");
}