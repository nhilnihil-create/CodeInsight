#include<iostream>
using namespace std;
int main(){
    int a,b,sum;
    cin>>a>>b;
    sum=a+b;
    if(sum%2==1){
        sum++;
    }
    cout<<sum/2;
}
