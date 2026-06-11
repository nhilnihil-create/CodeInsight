#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p,i=1,ans=0;
int main(void){
    cin>>n>>p;
    if(n==1){
        cout<<p<<endl;
        return 0;
    }
    if(n>40){
        cout<<1<<endl;
        return 0;
    }
    while(p>=(ll)pow(i,n)){
        if(p%(ll)pow(i,n)==0){
            ans=i;
        }
        i++;
    }
    cout<<ans<<endl;
    return 0;
}
