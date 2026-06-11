#include <iostream>
using namespace std;
int main(void){
int N,A,Z;
cin>>N>>A;
Z=N%500;
if(Z<=A){
    cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}