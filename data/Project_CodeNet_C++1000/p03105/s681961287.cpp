#include <iostream>
using namespace std;

int main(){
    int A, B, C, i;
    cin >> A >> B >> C;

    if(A*C <= B){
        cout << C;
    } else if(A > B){
        cout << 0;
    } else {
        for(i = 1; i*A <= B; i++){

        }
        cout << i-1;
    }
}