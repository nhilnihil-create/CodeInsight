#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    ll n;
    cin>>n;
    int cnt=1;
    bool flag=true;
    while(n>=10){
        if(n%10!=9) flag=false;
        n/=10;
        cnt++;
    }
    if(flag) cout<<n+9*(cnt-1)<<"\n";
    else cout<<n+9*(cnt-1)-1<<"\n";
    return 0;
}