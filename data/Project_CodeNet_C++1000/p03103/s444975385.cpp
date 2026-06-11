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
    int N, M, tmp1,tmp2;
    long long int ans = 0;
    cin >> N >> M;
    vector<pair<long long  int, long long int>> D(N);

    for (int i = 0; i < N; i++) {
        cin >> tmp1 >> tmp2;
        D[i].first = tmp1;
        D[i].second = tmp2;
    }

    sort(D.begin(), D.end());

    int i = 0;

    while (M != 0) {
        if (M > D[i].second) {
            ans += D[i].first * D[i].second;
            M -= D[i].second;
        }
        else {
            ans += D[i].first * M;
            M = 0;
        }
        i++;
    }

    cout << ans;

    return 0;
}