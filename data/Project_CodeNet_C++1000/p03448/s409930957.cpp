#include <iostream>
using namespace std;

int main() {
    int a, b, c, N;
    cin >> a >> b >> c >> N;

    int all_pattern_count = 0;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= c; k++) {
                int total = i*500 + j*100 + k*50;
                if (total == N)
                    all_pattern_count++;
            }
        }
    }
    cout << all_pattern_count << endl;

    return 0;
}
