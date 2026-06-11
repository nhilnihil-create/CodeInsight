#include "bits/stdc++.h"
using namespace std;

int main(){
    int N;
    cin>>N;
    int x=N/100;
    int a=100*x+10*x+x;
    if(N<=a){
        cout<<a<<endl;
    }else{
        cout<<a+111<<endl;
    }
    return 0;
}