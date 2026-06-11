#include <iostream>

using namespace std;

int main() {
    int N;  cin >> N;

    int ans = 0;
    for (int i = 3; i <= N; i+=2) {
        int cnt = 0;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                cnt += 2;
                if (j * j == i)
                    cnt--;
            }
        }
        if (cnt == 8)
            ans++;
    }
    cout << ans << endl;
    return 0;
}