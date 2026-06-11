#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
    long long n,k;
    cin>>n>>k;
    long long helf=0;
    long long zero=0;
    
    for(int i=1;i<=n;i++){
        if(i%k==(double)k/2) helf++;
        if(i%k==0) zero++;
    }
    
    cout<<helf*helf*helf + zero*zero*zero<<endl;
    
    return 0;
}