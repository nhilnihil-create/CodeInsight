#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <string>
using namespace std;
int main(){
    int A,B;
    int flagA=0;
    int K;
    cin>>A>>B>>K;
    while(K--){
        if(flagA==0){
            if(A%2==0){
            }else{
                A=A-1;
            }
            A=A/2;
            B=B+A;
            flagA=1;
        }else{
            if(B%2==0){
            }else{
                B=B-1;
            }
            B/=2;
            A=A+B;
            flagA=0;
        }

    }
    cout<<A<<" "<<B<<endl;
    
}