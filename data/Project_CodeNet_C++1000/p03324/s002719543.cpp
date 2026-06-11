#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
    int d,n;
    cin>>d>>n;
    if(n==100) printf("%.lf",pow(100,d)*101);
    else printf("%.lf",pow(100,d)*n);
    cout<<endl;
}