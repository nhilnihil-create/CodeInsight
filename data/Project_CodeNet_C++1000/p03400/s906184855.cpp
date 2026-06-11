#include <bits/stdc++.h>
using namespace std;

int Total(int D,int A_i){
    
    int i= 0,c =0;
    while(1){
        if(A_i*i + 1 > D) break;
         i++; c++;
    }
    return c;
}

int main() {
    
    int N,D,X;
    cin >> N >> D >> X;
    
    for(int i=0;i<N;i++){
        int A_i;
        cin >> A_i;
        X += Total(D,A_i);
    }
    
    cout << X << endl;
}