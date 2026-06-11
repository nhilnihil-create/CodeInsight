#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N, P = 0, W = 0, G = 0, Y = 0, cou = 0, i;
    string S;
    
    cin >> N;
    
    for(i = 0; i < N; i++){
    cin >> S;
    
    if(S == "P"){
        P = P + 1;
        
        if(P == 1)
        cou = cou + 1;
        
        else
        continue;
    }
    
    if(S == "W"){
        W = W + 1;
        
        if(W == 1)
        cou = cou + 1;
        
        else
        continue;
    }
    
    if(S == "G"){
        G = G + 1;
        
        if(G == 1)
        cou = cou + 1;
        
        else
        continue;
    }
    
    if(S == "Y"){
        Y = Y + 1;
        
        if(Y == 1)
        cou = cou + 1;
        
       else
       continue;
    }
    }
    if(cou == 3)
    cout << "Three" << endl;
    
    else
    cout << "Four" << endl;
}
