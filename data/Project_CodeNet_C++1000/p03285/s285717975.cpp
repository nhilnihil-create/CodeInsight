#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool can_buy = false;
    for (int i = 0; i <= n / 7; i++) {
        if ((n - i * 7) % 4 == 0) {
            can_buy = true;
        }
    }
    cout << (can_buy ? "Yes" : "No") << endl;
}
