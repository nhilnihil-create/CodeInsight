#include <iostream>
using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;
    if(N%K==0){cout<<0<<endl;}
    else{cout<<((N/K)+1)-(N/K)<<endl;}
}



