#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;

    bool found = false;
    int cmax = N / 4;
    int dmax = N / 7;

    for (int c=0; c<=cmax; ++c) {
        for (int d=0; d<=dmax; ++d) {
            int v = 4 * c + 7 * d;
            if (v == N) found = true;
        }
    }
    if (found) cout << "Yes" << endl;
    else cout << "No" << endl;
}
