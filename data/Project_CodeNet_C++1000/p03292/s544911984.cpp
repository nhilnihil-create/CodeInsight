#include<iostream>
using namespace std;
int main(){
    int A, a=101, b=0,i;
    for(i=1;i<=3;i++){
        cin>>A;
        if(A>b){
            b=A;
        }
        if(A<a){
            a=A;
        }
    }
    cout<<b-a;
    return 0;
}