#include <bits/stdc++.h>
#define N 200005
using namespace std;
typedef long long ll;
ll n,a[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],a[i]-=i;
    sort(a+1,a+n+1);
    ll mid=n/2,b[3]={a[mid],a[mid+1],a[mid-1]},ans=1e18;
    for(int i=0;i<=2;i++){
        ll cnt=0;
        for(int j=1;j<=n;j++)
            cnt+=abs(a[j]-b[i]);
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}