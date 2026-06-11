#include<bits/stdc++.h>
#define INFTY 1<<20
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const int MOD=1000000007;
int main() {

    int n;cin>>n;
    int a[n];rep(i,n)cin>>a[i];
    int r=0,sum=0;
    ll ans=0;
    for(int l=0;l<n;l++){
        while(r<n && (sum^a[r])==(sum+a[r])){
            //cout<<r<<sum<<endl;
            sum+=a[r];
            r++;
        }
        //cout<<l<<r<<endl;
        ans += r-l;
        if(l==r)r++;
        sum -= a[l];
    }
    cout<<ans<<endl;
    return 0;
}