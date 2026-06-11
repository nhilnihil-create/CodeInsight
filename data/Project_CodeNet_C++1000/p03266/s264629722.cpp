#include<iostream>
using namespace std;
int main(){
    long long int n,k;
    cin>>n>>k;
    long long int result=n/k;
    long long int result2=0;
    if(k%2==0)
    {
        result2+=((2*n)/k);
        result2-=result;

    }
    long long int result1=0;
    long long int r1=1,r2=1;
    for(long long int i=0;i<3;i++)
    {
        r1*=result;
        r2*=result2;
    }
    cout<<r1+r2;
    
}