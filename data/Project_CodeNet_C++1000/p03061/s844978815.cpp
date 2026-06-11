#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
int a[200005];
int b[200005];
int c[200005];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)b[i] = __gcd(a[i],b[i-1]);
    for(int i=n;i>=1;i--)c[i] = __gcd(a[i],c[i+1]);
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,__gcd(b[i-1],c[i+1]));
    }
    cout<<ans<<endl;
}
