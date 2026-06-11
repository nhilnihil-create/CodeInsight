#include <iostream>
using namespace std;

int main() {

    int N;
    int Y;

    int x = 0;
    int y = 0;
    int z = 0;

    int x10000 = 10000;
    int y5000  = 5000;
    int z1000  = 1000;

    cin >> N >> Y;

    for (int i = 0; i <= N; i++) {

        if ((x10000 * i) == Y && i == N){
            x = i;
            y = 0;
            z = 0;

            cout << x << " " << y << " " << z << endl;
            return 0;
        }

        for (int j = 0; j <= N - i; j++) {
            x = i;
            y = j;
            z = N - i - j;

             if ((x10000 * x) + (y5000 * y) + (z1000 * z) == Y && x + y + z == N) {
                cout << x << " " << y << " " << z << endl;
                return 0;
            }
        }
    }

    cout << "-1 -1 -1" << endl;

    return 0;

}