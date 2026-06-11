#include<iostream>
using namespace std;
int main(){
    int d,n;
    cin>>d>>n;
    int result=1;
    while(d>0){
        result*=100;
        d--;
    }
    if(n==100)
    n++;
    result*=n;
    cout<<result;
}