#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int nedan = 0;
    if (A+B>C*2) {
        if (X<Y) {
            nedan = X * C * 2;
            if (B < C * 2) {
                nedan += (Y - X) * B;
            } else {
                nedan += (Y - X) * C * 2;
            }
        } else {
            nedan = Y * C * 2;
            if (A < C * 2) {
                nedan += (X - Y) * A;
            } else {
                nedan += (X - Y) * C * 2;
            }
        }
    } else {
        nedan = A*X + B*Y;
    }
    cout << nedan << endl;
}