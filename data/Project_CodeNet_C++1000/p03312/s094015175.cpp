#include<bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int maxm = maxn*10;
const int inf = 0x3f3f3f3f;
typedef long long ll;

int a[maxn];
ll sum[maxn];
ll cal(int l,int r){
    return sum[r] - sum[l-1];
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) {
        cin>>a[i]; sum[i] = sum[i-1] + a[i];
    }
    ll ans = 2e18;
    int l = 1,r = 3;
    for(int i = 2;i<=n-2;i++) {
        while(l+1<i && abs(cal(1,l)-cal(l+1,i)) >= abs(cal(1,l+1)-cal(l+2,i))) ++l;
        while(r+1<n && abs(cal(i+1,r)-cal(r+1,n)) >= abs(cal(i+1,r+1)-cal(r+2,n))) ++r;
        vector<ll>v;
        v.push_back(cal(1,l));
        v.push_back(cal(l+1,i));
        v.push_back(cal(i+1,r));
        v.push_back(cal(r+1,n));
        sort(v.begin(),v.end());
        ans = min(ans,abs(v[0] - v[3]));
    }
    cout<<ans<<'\n';
    return 0;
}