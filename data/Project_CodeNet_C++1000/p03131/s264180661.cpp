#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int k,a,b;
    cin>>k>>a>>b;
    ll ans=0;
    if(k<=a||b-a<=2)ans=k+1;
    else{
        if(k%2==a%2)ans=a+ll(b-a)*((k-a+1)/2)+1;
        else ans=a+ll(b-a)*((k-a+1)/2);
    }
    cout<<ans<<endl;
    return 0;
}
