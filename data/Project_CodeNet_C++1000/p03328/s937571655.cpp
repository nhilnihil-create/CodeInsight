#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int n=b-a+1;
    n-=2;
    int result=((n)*(n+1))/2;
    cout<<result-a;
}