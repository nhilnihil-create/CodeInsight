#include<bits/stdc++.h>
using namespace std;
int main(){
    int D, N;
    cin >> D >> N;
    if(D == 0){
        if(N == 100){
            cout << N + 1 << endl;
        }
        else{
            cout << N << endl;
        }
    }
    else if(D == 1){
        if(N == 100){
            cout << (N + 1) * 100 << endl;
        }
        else{
            cout << N * 100 << endl;
        }
    }
    else{
        if(N == 100){
            cout << (N + 1) * 10000 << endl;
        }
        else{
            cout << N * 10000 << endl;
        }
    }
    return 0;
}