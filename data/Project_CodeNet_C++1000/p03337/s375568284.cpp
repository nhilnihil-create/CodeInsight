#include <iostream>

using namespace std;

int main(){
    int A,B,Max;

    cin >> A >>B;
    Max=A+B;
    if(A-B >Max){
        Max= A-B;
    }
    if(A*B >Max){
        Max= A*B;
    }

    cout <<Max;
    return 0;
}
