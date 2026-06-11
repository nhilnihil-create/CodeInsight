#include <iostream>
using namespace std;
int main() {
    int N, T;
    cin >> N >> T;
    int minC = 1001;
    for (int i=0; i<N; i++) {
        int c, t;
        cin >> c >> t;
        if (t <= T) {
            minC = min(minC, c);
        }
    }
    if (minC > 1000) {
        cout << "TLE" << endl;
    } else {
        cout << minC << endl;
    }
}