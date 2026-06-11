#include <iostream>
using namespace std;

int main() {
    int X;
    int Y;
    cin >> X >> Y;
    for (int i = 1; i <= 2 * Y; i++) {
        if ((i * X) % Y !=0 && i * X != X) {
            cout << i * X << "\n";
            break;
        } else if (X % Y == 0) {
            cout << "-1 \n";
            break;
        }
        if (i == 2 * Y) {
            cout << "-1 \n";
            break;
        }
    }
}
