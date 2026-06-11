#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    int sum = 0;
    int num = 0;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        sum = 0;
        num = i;
        while (num !=0) {
            sum += num % 10;
            num /=10;
        }

        if (sum >= A && sum <= B) {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}