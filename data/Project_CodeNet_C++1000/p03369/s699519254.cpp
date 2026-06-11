#include "bits/stdc++.h"

using namespace std;

void Main() {
    string S;
    cin >> S;
    int ans = 700;
    for (int i = 0; i < 3; ++i) {
        if (S[i] == 'o') {
            ans += 100;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
