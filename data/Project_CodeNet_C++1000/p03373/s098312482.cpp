#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    // Your code here!
    long long A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    
    long long ans = A * X + B * Y;
    
    int piza_Max = max(X, Y);
    
    for(int i = 1; i <= piza_Max; i++){
        
        long long piza_Now_Money;
        long long now_X = X - i;
        long long now_Y = Y - i;
        long long now_C = i * 2;
        
        if(now_X >= 0 && now_Y >= 0) piza_Now_Money = A * now_X + B * now_Y + C * now_C;
        if(now_X < 0) piza_Now_Money = B * now_Y + C * now_C;
        if(now_Y < 0) piza_Now_Money = A * now_X + C * now_C;

        ans = min(ans, piza_Now_Money);
    }

    cout << ans << endl;
}