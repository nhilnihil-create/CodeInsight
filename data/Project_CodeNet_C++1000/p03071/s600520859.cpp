#include <bits/stdc++.h>
using namespace std;

int main(void){
 
    int A,B,sum =0;
    cin >> A >> B;
    
    if(A >= B){
        sum += A;
        A--;
    }
    else{
        sum += B;
        B--;
    }
    
    if(A >= B){
        sum += A;
        A--;
    }
    else{
        sum += B;
        B--;
    }
    
    cout << sum <<endl;
}