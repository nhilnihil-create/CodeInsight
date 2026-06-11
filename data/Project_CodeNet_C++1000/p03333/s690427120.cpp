#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
#define inf 1000000001
using namespace std;
#define N 100005
int n,now,a[N],b[N];ll ans;
int main(){
    scanf("%d",&n);
    rep (i,1,n) scanf("%d%d",&a[i],&b[i]);
    n++;
    sort(&a[1],&a[n+1]);sort(&b[1],&b[n+1]);
    rep (i,1,n) ans+=max(0,a[n-i+1]-b[i]);ans*=2;
    cout<<ans<<'\n';
    return 0;
}