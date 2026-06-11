#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long a,b;
    cin>>a>>b;
    long long cnt=0;
    
    for(long long i=1;i<=a;i+=2) cnt++;
    
    if(cnt>=b) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
