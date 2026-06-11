#include<iostream>
using namespace std;
int main(){
    long long int  n,m;
    cin>>n>>m;
    if(n>m)
    {
        long long int temp=n;
        n=m;
        m=temp;
    }
    if(n==1&&m==1){
        cout<<"1";
        return 0;
    }
    if(n==1)
    {
        cout<<(m-2);    
    }
    else
    cout<<(n-2)*(m-2);
}