#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    ll a,b,ans;
    cin>>a>>b;
    a--;
    if(a%2==0){
        if((a/2)%2==1)a++;
    }
    else{
        if(((a+1)/2)%2==1)a=1;
        else a=0;
    }
    if(b%2==0){
        if((b/2)%2==1)b++;
    }
    else{
        if(((b+1)/2)%2==1)b=1;
        else b=0;
    }
    ans=a^b;
    cout<<ans<<endl;
    return 0;
}