#include <iostream>
using namespace std;

int n, T;
int main() {
    cin >> n >> T;
    int p = 1e9;
    for(int i = 0; i < n; ++i) {
        int c, t;
        cin >> c >> t;
        if(t > T) continue;
        p = min(p, c);
    }
    if(p == 1e9) {
        cout << "TLE" << endl;
    } else {
        cout << p << endl;
    }
}
