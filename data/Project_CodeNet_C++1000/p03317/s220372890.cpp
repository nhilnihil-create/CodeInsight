#include <iostream>

using namespace std;

int main() {
    int N;
    int K;
    cin >> N >> K;
    int index = 0;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        if (tmp == 1) {
            index = i;
            break;
        }
    }

    int ans = 0;
    if (index != 0) {
        int p = index - K + 1;
        ++ans;
        if (p < 0) {
            index = K - 1;
        } else {
            while (p > 0) {
                p = p - K + 1;
                ++ans;
            }
            index = index + (-1 * p);
        }
    }

    while (index < (N - 1)) {
        index = index + K - 1;
        ++ans;
    }

    cout << ans << endl;
}