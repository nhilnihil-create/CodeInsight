#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int price=0;

    int rest;


    if(A+B<2*C){
        cout << A*X+B*Y << endl;
    }

   
    else{
        if(X>Y){
            price=price+2*C*Y;
            rest=X-Y;
            cout << min(A,2*C)*rest+price << endl;
        }
        else{
            price=price+2*C*X;
            rest=Y-X;
            if(B>2*C){
                cout << price+2*C*rest << endl;
            }
            else{
                cout << price+B*rest << endl;
            }
        }
    }
}
