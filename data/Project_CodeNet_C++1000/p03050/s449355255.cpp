#include<iostream>
int main(){
    long N,a=0;
    std::cin>>N;
    for(long i=1;i*i+i<N;i++)if(N%i==0)a+=N/i-1;
    printf("%ld\n",a);
}
