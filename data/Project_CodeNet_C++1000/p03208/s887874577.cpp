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
    int N, K, ans = 1001001001, tmp;
    cin >> N >> K;
    vector<int>H(N);

    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    sort(H.begin(), H.end());

    for (int i = 0; i <= N- K; i++) {
        ans = min(ans, H[i + K - 1] - H[i]);
    }

    cout << ans;

    return 0;

}

