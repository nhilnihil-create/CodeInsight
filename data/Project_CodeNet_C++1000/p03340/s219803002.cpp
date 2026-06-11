#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll n,a[200000],sum,x,ans;

int main(){
    cin>>n;
    rep(i,n)cin>>a[i];
    rep(i,n){
        while(x<n&&(sum^a[x])==sum+a[x]){
            sum+=a[x];
            x++;
        }
        ans+=x-i;
        sum^=a[i];
    }
    cout<<ans<<endl;
}