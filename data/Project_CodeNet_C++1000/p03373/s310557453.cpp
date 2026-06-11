#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    // int ans = 0;
    // if(X >= Y){
    //     if(A + B <= C * 2) ans += (A + B) * Y + A * (X - Y);
    //     else if(A >= C * 2) ans += 2 * C * Y + 2 * C * (X - Y);
    //     else ans += 2 * C * Y + A * (X - Y);
    // }else{
    //     if(A + B <= C * 2) ans += (A + B) * X + A * (Y - X);
    //     else if(B >= C * 2) ans += 2 * C * X + 2 * C * (Y - X);
    //     else ans += 2 * C * X + B * (Y - X);
    // }

    int price_ans = A * X + B * Y;
    for(int i = 0; i <= 100000; i++){
        int price = i * 2 * C + A * max(0, X-i) + B * max(0, Y-i);
        price_ans = min(price_ans, price);
    }

    cout << price_ans << endl;


    return 0;
}