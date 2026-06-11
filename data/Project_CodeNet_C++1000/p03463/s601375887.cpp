#include <iostream>
using namespace std;
int main(void){
    int N,A,B;
    cin >> N >> A >> B;
    
    int count = 0;
    int memA0, memB0;
    int memA1, memB1;
    
    memA0 = A-1; memA1 = A-1;
    memB0 = B+1; memB1 = B+1;
    
    while(1){
        
    if(!count%2) {
        if(A==memA0 && B==memA0) { cout << "Draw"; return 0; }
        memA0 = A; memB0 = B;
    }
    
    else {
        if(A==memA1 && B==memB1) { cout << "Draw"; return 0; }
        memA1 = A; memB1 = B;
    }
    
    if(A+1 != B) A += 1;
    else if(A-1 != 0) A -= 1;
    else {cout << "Borys"; return 0;}
    
    if(B-1 != A) B -= 1;
    else if(B+1 != N+1) B += 1;
    else {cout << "Alice"; return 0;}
    
    count++;
    
    }
}
