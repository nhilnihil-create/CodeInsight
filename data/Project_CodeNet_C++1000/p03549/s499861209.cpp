#include<iostream>
#include<cmath>
using namespace std;

int main(){
    double n,m;
    cin>>n>>m;
    cout<<(int)(1900*m+100*(n-m))*powl(2,m)<<endl;
}