#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <utility>
#include <set>
#include <unordered_set>
#include <stack>
#include <iterator>
#include <random>
#include <fstream>
#include <chrono>
#include <math.h>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < n; ++i)

double dp[301][301][301];

int32_t main()
{
    int n;
    cin >> n;
    for (int c3 = 0; c3 <= n; c3++) {
        for (int c2 = 0; c2 + c3 <= n; c2++) {
            for (int c1 = 0; c3 + c2 + c1 <= n; c1++) {
                if (c1 == 0 && c2 == 0 && c3 == 0) {
                    continue;
                }
                double sum = n;
                if (c1 > 0) {
                    sum += c1 * dp[c1 - 1][c2][c3];
                }
                if (c2 > 0) {
                    sum += c2 * dp[c1 + 1][c2 - 1][c3];
                }
                if (c3 > 0) {
                    sum += c3 * dp[c1][c2 + 1][c3 - 1];
                }
                dp[c1][c2][c3] = sum / (c1 + c2 + c3);
            }
        }
    }
    int c1, c2, c3;
    c1=c2=c3=0;
    forn(i,n) {
        int x;
        cin >> x;
        if (x == 1) {
            c1++;
        } else if (x == 2) {
            c2++;
        } else {
            c3++;
        }
    }
    cout.precision(16);
    cout << fixed << dp[c1][c2][c3] << endl;
    return 0;
}