#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>


using namespace std;

int main() {
    int D, N, ans;
    cin >> D >>N;
    if (N == 100) {
        N = 101;
    }
    ans = pow(100, D) * N;

    cout << ans;

    return 0;

}

