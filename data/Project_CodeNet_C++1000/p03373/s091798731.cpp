#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int A, B, C, X, Y, cost, cost2;
    cin >> A >> B >> C >> X >> Y;
    if(X >= Y){
        cost = C * 2 * Y + A * (X - Y); 
        cost2 = C * 2 * X;
    } else {
        cost = C * 2 * X + B * (Y - X);
        cost2 = C * 2 * Y;
    }

    cost = cost < cost2 ? cost : cost2;

    if(cost < A * X + B * Y){
        cout << cost << endl;
    } else {
        cout << A * X + B * Y << endl;
    }
}