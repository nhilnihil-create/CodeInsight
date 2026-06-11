#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int a, b; cin >> a >> b;
    if ((a * b) % 2 == 0) printf("%s\n", "Even");
    else printf("%s\n", "Odd");
}
