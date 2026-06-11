#include <bits/stdc++.h>
using namespace std;

int A,B,C,X,Y;

int main(){
    cin>>A>>B>>C>>X>>Y;

    long long ans = 0;;

    if(A+B>=2*C){
        int ab = 2 * min(X,Y);
        int a = X - ab/2;
        int b = Y - ab/2;

        if(A>=2*C){
            ab += a*2;
            a=0;
        }

        if(B>=2*C){
            ab += b*2;
            b=0;
        }
        ans = a*A + b*B + ab*C;
        
    } else {
        ans = X*A + Y*B;
    }
    
    cout << ans << endl;

    return 0;
}
