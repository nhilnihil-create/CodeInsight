#include<iostream>
using namespace std;

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    int a;
    cin>>a;
    int d=gcd(a,2);
    cout<<a*2/d;
}