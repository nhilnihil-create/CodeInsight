#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,a,b,ans;
    a = 2;
    b = 1;
    ans = 0;
    cin>>n;
    if(n==1) cout<<1<<endl;
    else{
        for(int i=1;i<n;i++){
        ans = a+b;
        a=b;
        b=ans;
    }
    cout<<ans<<endl;
    }
    
}