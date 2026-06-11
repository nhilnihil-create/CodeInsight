#include<iostream>
using namespace std;
int main(){
    int a,b,sum;
    cin>>a>>b;
    sum=a+b;
    if(sum%2==0){
        cout<<sum/2<<endl;
    }else{
        cout<<(sum+1)/2<<endl;
    }
    return(0);
}