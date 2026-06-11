// Cakes and Donuts
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    bool CanBuy = false;
    for (int i = 0; i < (N/4+1); ++i) {
        for (int j = 0; j < (N/7+1); ++j) {
            int total = 4 * i + 7 * j;
            if (total == N) {
                CanBuy = true;
                break;
            }
        }
    }
    if (CanBuy) cout << "Yes" << endl;
    else cout << "No" << endl;
}