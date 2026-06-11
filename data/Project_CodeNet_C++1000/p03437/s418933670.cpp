#include <iostream>

using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;

    if (X % Y == 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << X << endl;
    return 0;
}