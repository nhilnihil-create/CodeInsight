#include <iostream>

using namespace std;

int main (void) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int left = A + B;
    int right = C + D;
    if ( left > right )
        cout << "Left";
    else if ( left < right )
        cout << "Right";
    else
        cout << "Balanced";
    cout << endl;
}
