#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int x;
    cin >> x;
    for (int i = x; i >= 1; i--) {
        for (int j = 2; j * j <= i; j++) {
            int n = i;
            while (n > 1 && n % j == 0) {
                n /= j;
            }
            if (n == 1) {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << 1 << endl;
}
