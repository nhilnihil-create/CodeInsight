#include <iostream>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int sum = 0;
    if(A + B <= C*2) {
        sum = A*X + B*Y;
    } else if(X >= Y) {
        if(A <= C*2) {
            sum = C*2*Y + A*(X-Y);
        } else {
            sum = C*2*X;
        }
    } else {
        if(B <= C*2) {
            sum = C*2*X + B*(Y-X);
        } else {
            sum = C*2*Y;
        }
    }
    cout << sum << endl;
}