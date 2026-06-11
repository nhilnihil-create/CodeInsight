#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    if (n < 1200) return !(cout << "ABC" << endl);
    if (n < 2800) return !(cout << "ARC" << endl);
    cout << "AGC" << endl;
    return 0;
}
