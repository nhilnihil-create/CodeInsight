#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B;
    cin >> A >> B;
    int ans = 0;
    for (int i = A; i <= B; ++i) {
        string s = to_string(i);
        if (s[0] == s[4] && s[1] == s[3]) {
            ++ans;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
