#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
int main(){
    cin>>n>>k;
    if(k==0) ans=n*n;
    else
    {
        for(int i=k+1;i<=n;i++)
        {
            ans+=(n/i)*(i-k);
            if(n%i>=k) ans+=n%i-k+1;
        }
    }
    cout<<ans;
    return 0;
}
//68871358
//76140264
//25446011
//200841159