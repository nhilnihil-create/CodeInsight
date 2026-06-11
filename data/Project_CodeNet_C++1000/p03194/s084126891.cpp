#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    ll n,p,a=1,ans;
    cin>>n>>p;
    if(n==1){cout<<p<<endl;return 0;}
    while(pow(a,n)<=p){
        if(p%(ll)pow(a,n)==0){
            ans=a;
        }
        a++;
    }
    cout<<ans<<endl;
}
