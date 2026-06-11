#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B, C;
    cin >> A >> B >> C;
    cout << min(C, B / A) << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
