#include<iostream>
using namespace std;
int main(){
    int A, B, C, X, Y, money;
    cin >> A >> B >> C >> X >> Y;

    if(A + B >= 2 * C){

        if(X <= Y){
            if(B <= 2 * C) money = X * 2 * C + (Y - X) * B;
            else money = Y * 2 * C;
        }
        else{
            if(A <= 2 * C) money = Y * 2 * C + (X - Y) * A;
            else money = X * 2 * C;
        }

    }

    else money = A * X + B * Y;
    cout << money << endl;
}
