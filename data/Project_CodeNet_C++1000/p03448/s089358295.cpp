
#include <iostream>
#include <iomanip>
using namespace std;

void Main() {
    // input
    int A, B, C;
    int X;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> X;

    // translate
    int ans = 0;

    for (int i = 0; i <= A; i++) {
        for (int j = 0; j <= B; j++) {
            for (int k = 0; k <= C; k++) {
                if (500 * i + 100 * j + 50 * k == X) {
                    ans++;
                }
            }
        }
    }


    // output
    cout << ans << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
