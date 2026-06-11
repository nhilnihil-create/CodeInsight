#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int A[3];
    for(int i=0;i<3;++i)cin>>A[i];

    sort(A,A+3);
    int X=A[2];

    if((3*X)%2==(A[0]+A[1]+A[2])%2){
        cout<<(2*X-A[1]-A[0])/2;

    }else{
        cout<<(3*(X+1)-A[1]-A[2]-A[0])/2;
    }

}
