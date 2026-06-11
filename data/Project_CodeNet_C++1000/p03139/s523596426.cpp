#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    
    int max;
    if(a>=b)max=b;
    if(b>a)max=a;
    cout<<max;
    
    int min;
    if(a+b<=n)min=0;
    if(a+b>n)min=a+b-n;
    cout<<" "<<min<<endl;
}