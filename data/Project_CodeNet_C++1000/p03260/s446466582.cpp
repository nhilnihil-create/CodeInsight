#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B;
    cin >> A >> B;

    cout << ((A % 2 == 1 && B % 2 == 1) ? "Yes" : "No") << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
