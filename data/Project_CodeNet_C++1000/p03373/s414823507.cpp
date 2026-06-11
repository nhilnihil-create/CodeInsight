#include <iostream>
#include <vector>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    if (A + B <= 2 * C) {
        int cost = A * X + B * Y;
        cout << cost << endl;
    }
    else {
        if (X <= Y) {
            int numAB = 2 * X;
            int cost1 = C * numAB + B * (Y - X); 
            numAB = 2 * Y;
            int cost2 = C * numAB;
            int cost = min(cost1, cost2);
            cout << cost << endl;
        }
        else {
            int numAB = 2 * Y;
            int cost1 = C * numAB + A * (X - Y); 
            numAB = 2 * X;
            int cost2 = C * numAB;
            int cost = min(cost1, cost2);
            cout << cost << endl;
        }
    }
}