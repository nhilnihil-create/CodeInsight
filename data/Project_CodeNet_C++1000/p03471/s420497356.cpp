#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <bitset>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
    int K, Y;
    vector<int> kane(3, -1);
    scanf("%d %d", &K, &Y);
    int yen = Y;
    for (int m = 0; m <= K; m++) {
        for (int g = 0; g <= K - m; g++) {
            int yen = Y - ((10000 * m) + (5000 * g));
            if (yen % 1000 == 0 && yen / 1000 == K - (m + g)) {
                kane[0] = m;
                kane[1] = g;
                kane[2] = K - (m + g);
            }
        }
    }
    cout << kane[0] << " " << kane[1] << " " << kane[2] << endl;
}