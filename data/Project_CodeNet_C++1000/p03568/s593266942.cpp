#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, x;
    int even_number = 0;
    int ans;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x % 2 == 0) {
            even_number++;
        }
    }

    ans = pow(3, N);
    ans -= pow(2, even_number);

    cout << ans << endl;
}
