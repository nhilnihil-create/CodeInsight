#include<iostream>
using namespace std;

int main(void){
    int N,H,W;

    cin>>N>>H>>W;

    H=N-H+1;
    W=N-W+1;

    cout<<H*W<<endl;

    return 0;
}
