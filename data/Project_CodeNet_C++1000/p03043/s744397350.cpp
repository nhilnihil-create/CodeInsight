#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>

using namespace std;
long double possibility(double N, int K);


int main() {
    long long int N, K;
    cin >> N >> K;

    long double ans = 0;
    ans = possibility(N, K);

    cout << setprecision(15) << ans;

    return 0;
}

long double possibility(double N, int K) {
    long double ans = 0, percentage;
    int j, score;
    for (int i = 1; i <= N; i++) {
        percentage = 0;
        j = 0;
        score = 0;
        while (score < K) {
            score = i *  pow(2, j);
            percentage = 1 / N * pow(0.5, j);
            j++;
        }
        ans += percentage;
    }
    return ans;
}