#include <iostream>
using namespace std;

int main(void) {

    int N;
    cin >> N;

    int L;
    int sum = 0;
    int max = 0;
    for (int i = 0; i < N; i++) {
        cin >> L;
        sum += L;
        if (max < L) {
            sum += max;
            max = L;
            sum -= L;
        }
    }

    if (sum > max) cout << "Yes";
    else cout << "No";

    return 0;
}
