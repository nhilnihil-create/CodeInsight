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
    int ans =0, A, B, C;
    vector<int> N;

    cin >> A >> B >> C;

    N.push_back(A);
    N.push_back(B);
    N.push_back(C);


    if (A % 2 + B % 2 + C % 2 == 1) {
        ans += 1;
        for (int i = 0; i < 3; i++) {
            if (N[i] % 2 == 0) {
                N[i] += 1;
            }
        }
    }
    else if (A % 2 + B % 2 + C % 2 == 2) {
        ans += 1;
        for (int i = 0; i < 3; i++) {
            if (N[i] % 2 == 1) {
                N[i] += 1;
            }
        }
    }

    sort(N.begin(), N.end());

    ans += (2 * N[2] - N[1] - N[0]) / 2;

    cout << ans;

    return 0;
}