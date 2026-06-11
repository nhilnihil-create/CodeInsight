#include <iostream>
#include <vector>

using namespace std;

int const INF = 10001;

int main() {
    int n, T;
    int c, t;
    int result = INF;

    cin >> n >> T;

    for(int i = 0; i < n; i++) {
        cin >> c >> t;

        if(t <= T) {
            if(c < result) {
                result = c;
            }
        }
    }

    if(result == INF) {
        cout << "TLE" << endl;
    } else {
        cout << result << endl;
    }

}