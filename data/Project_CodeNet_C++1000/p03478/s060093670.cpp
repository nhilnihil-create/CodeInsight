#include <iostream>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int result = 0; // 答えを格納する変数
    for (int n = 1; n <= N; ++n) {
        int sum = 0;
        int n2 = n;
        while (n2) {
            sum += n2 % 10;
            n2 /= 10;
        }
        if (sum >= A && sum <= B) result += n;
    }
    cout << result << endl;
}