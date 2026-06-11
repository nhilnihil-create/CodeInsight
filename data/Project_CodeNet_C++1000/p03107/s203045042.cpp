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
    int N, N1 = 0, N0 = 0;
    string S;

    cin >> S;

    N = S.size();

    for (int i = 0; i < N; i++) {
        if (S[i] == '0') {
            N0++;
        }
        else {
            N1++;
        }
    }

    cout << min(N0, N1) * 2;

    return 0;
}