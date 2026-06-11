#include<bits/stdc++.h>
using namespace std;

int main(){
    int M,K; cin >> M >> K;
    int N=pow(2,M);
    if(M==1&&K==0){
        cout << "0 0 1 1" << endl;
        return 0;
    }
    if(N<=K){
        cout << -1 << endl;
        return 0;
    }
    if(M==1&&K==1){
        cout << -1 << endl;
        return 0;
    }
    for(int i=0;i<N;i++){
        if(i!=K) cout << i << " ";
    }
    cout << K << " ";
    for(int i=N-1;i>=0;i--){
        if(i!=K) cout << i << " ";
    }
    cout << K << endl;
}