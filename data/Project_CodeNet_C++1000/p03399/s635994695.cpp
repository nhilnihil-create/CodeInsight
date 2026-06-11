#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int ans = min(A, B) + min(C, D);
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
