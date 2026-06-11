#include <bits/stdc++.h>
using namespace std;

int main(void){

    int N,M,X,A,l=0,r=0;
    cin >> N >> M >> X;
    int data[N+1];
    for(int i=0;i<N+1;i++) data[i] = 0;
    
    for(int i=0;i<M;i++){
        cin >> A;
        data[A] = 1;
    }
    
    for(int i=X;i<N+1;i++){
        if(data[i] == 1) l++;
    }
    
    for(int i=X;i>=0;i--){
        if(data[i] == 1) r++;
    }
    cout << min(l,r) << endl;
}