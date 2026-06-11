#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int D, N, ans = 0; cin >> D >> N;
    int i = 0, j = 1;
    if (D == 0) {
        if (N == 100) ans = 101;
        else {
            while(i < N) {
                if (j % 100 != 0) i++, ans = j, j++;
            }
        }
    }
    else if (D == 1) {
        j = 100;
        while(i < N) {
            if (j % 100 == 0) i++, ans = j, j += 100;
        }
        if (N == 100) ans = 10100;
    }
    else if (D == 2) {
        j = 10000;
        while(i < N) {
            if (j % 10000 == 0) i++, ans = j, j += 10000;
        }
        if (N == 100) ans = 1010000;
    }
    cout << ans << endl;
}
