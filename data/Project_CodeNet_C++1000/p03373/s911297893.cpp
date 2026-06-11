#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    long long X,Y;
    cin >> X >> Y;

    int total=0,a=0,b=0,c=0;

    if((A + B) > 2*C ){
        if(X >Y){
            if((X - Y)*2 *C < (X - Y)*A){
               c = 2 *  X;
               total = c * C;
            }else{
                a = X - Y;
                c = 2 * Y;
                total = A * a + C * c;
            }
        
        }else{
            if((Y - X)*2*C < (Y - X)*B){
                c = 2 * Y;
                total = c * C;
            }else{
                b = Y - X;
                c = 2 * X;
                total = B * b + C * c;
            }
        }
    }else{
        a = X;
        b = Y;
        total = A * a + B * b;
    }

    cout << total << endl;
}