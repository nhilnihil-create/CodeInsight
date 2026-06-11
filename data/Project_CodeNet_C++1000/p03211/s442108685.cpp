#include "bits/stdc++.h"

using namespace std;

void Main() {
    string S;
    cin >> S;

    int ans = 1000;
    for (int i = 0; i < S.size() - 2; ++i) {
        int lunlun = atoi(S.substr(i, 3).c_str());
        ans = min(ans, abs(lunlun - 753));
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
