#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, four, seven;
    cin >> N;

    if (N % 4 == 0 || N % 7 == 0) {
        cout << "Yes" << endl;
        return 0;
    } else if (N < 4 || N < 7) {
        cout << "No" << endl;
        return 0;
    } else {
        if (7 < N) {
            seven = N / 7;
            for(int i = 1; i <= seven; i++) {
                if ((N - 7*i) % 4 == 0) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
        if (4 < N) {
            four = N / 4;
            for(int i = 1; i <= four; i++) {
                if ((N - 4*i) % 4 == 0) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
