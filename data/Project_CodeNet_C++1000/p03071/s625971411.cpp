#include<iostream>
using namespace std;

int main(void){
    int A,B,i,Sum=0;
    cin >> A >> B;

    for(i=0;i<2;i++){
        if(A>B){
            Sum += A;
            A--;
        }else{
            Sum += B;
            B--;
        }
    }

    cout << Sum;

    return 0;
}