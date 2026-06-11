#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);i++)
using ll=long long;

int main() {
    int n,a,b;
    cin>>n>>a>>b;
   
    int ans=0;
    
    rep(i,n){
        int s;
        s=i%10+(i/10)%10+(i/100)%10+(i/1000)%10+(i/10000)%10;
        if(s>=a && s<=b)ans+=i;
    }
    cout<<ans;
    
    return 0;
    }

