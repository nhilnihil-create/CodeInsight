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
    int N, * A1, * A2, sum, ans = 0;
    cin >> N;
    A1 = new int[N];
    A2 = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> A1[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> A2[i];
    }

    for (int i = 0; i < N; i++) {
        sum = 0;
        for (int j = 0; j < N; j++) {
            if (j < i) {
                sum += A1[j];
            }
            else if (j == i) {
                sum += A1[j] + A2[j];
            }
            else {
                sum += A2[j];
            }
            ans = max(ans, sum);
        }
    }

    cout << ans;

    return 0;

}

