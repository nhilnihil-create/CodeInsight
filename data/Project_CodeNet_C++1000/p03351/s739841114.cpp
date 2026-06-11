#include <iostream>
using namespace std;
int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    if (max(a, b) - min(a, b) <= d && max(b, c) - min(b, c) <= d || (max(a, c) - min(a, c) <= d)) printf("%s\n", "Yes");
    else printf("%s\n", "No");
}