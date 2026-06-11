#include <bits/stdc++.h>
using namespace std;

int main(){
    int D,N;
    cin >>D>>N;
    if(N!=100){    
    long long count=N;
    for(int i=0;i<D;++i){
        count*=100;
    }
    cout <<count <<endl;
    }
    else{
    long long count=101;
    for(int i=0;i<D;++i){
        count*=100;
    }
    cout <<count <<endl;
    }

}