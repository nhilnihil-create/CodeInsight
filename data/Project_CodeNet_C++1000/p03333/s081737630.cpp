#include<bits/stdc++.h>
#define maxn 520300
using namespace std;
typedef long long ll;
ll ans,a[maxn],b[maxn],sum,n,r;
bool cmp(int x,int y){
    return x>y;
}

int main(){
    cin >> n;
    for (int i=0;i<n;i++){
        scanf("%lld%lld",&a[i],&b[i]);
        if (a[i]>0) ans=max(ans,a[i]*2);
        if (b[i]<0) ans=max(ans,-b[i]*2);
    }
    sort(a,a+n+1,cmp); sort(b,b+n+1); sum=0; int j=0;
    for (j=0;j<=n;j++) if (a[j]-b[j]>0) sum+=a[j]-b[j];
    ans=max(ans,sum*2);
    cout << ans << endl;
}
