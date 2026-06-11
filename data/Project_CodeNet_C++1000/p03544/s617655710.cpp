#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long N;cin>>N;
    long long A,B,C;A=2;B=1;C=1;
    for(long long i=0;i<N-1;i++){
        C=A+B;
        A=B;
        B=C;
    }
    cout<<C<<endl;
    return 0;
}