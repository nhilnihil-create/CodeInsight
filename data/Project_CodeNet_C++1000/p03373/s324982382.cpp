#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, X, Y; 
    cin >> A >> B >> C >> X >> Y;

    int res = 1 << 30;
    for (int c = 0; c <= max(2*X, 2*Y); c++)
    {
        int a = max(0, X - c/2);
        int b = max(0, Y - c/2);
        int price = A*a + B*b + C*c;
        if(price < res) res = price;
    }
    
    cout << res << endl;


    return 0;
}