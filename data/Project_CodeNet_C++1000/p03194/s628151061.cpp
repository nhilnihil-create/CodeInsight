#include<iostream>
#include<cmath>
using namespace std;
int main(){
    unsigned long N,P;

    cin>>N>>P;



    long double n,m,k;
    k=1.0/N;

    n=pow(P,k);
    m=floor(n);

    for (unsigned long i=m+1;1<=i;--i){

        long z;
        z=pow(i,N);

        if(P%z==0){
            cout<<i<<endl;
            break;
        }
    }

}
