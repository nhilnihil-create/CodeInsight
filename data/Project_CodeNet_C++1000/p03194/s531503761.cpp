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
    else{
        for(int i=1;i<=1000000;i++){
            if(p%(ll)pow(i,n)==0){
                ans=i;
            }
            if(p<=(ll)pow(i,n)){
                break;
            }
            
        }
        cout<<ans<<endl;
        return 0;
    }
}
