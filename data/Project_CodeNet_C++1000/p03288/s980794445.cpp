#include <iostream>
using namespace std;
int main() {
    int R; cin >> R;
    if (R < 1200) printf("%s\n", "ABC");
    else if (R < 2800) printf("%s\n", "ARC");
    else printf("%s\n", "AGC");
}