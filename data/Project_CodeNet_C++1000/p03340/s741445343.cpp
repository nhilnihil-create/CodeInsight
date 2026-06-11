#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
ll mod=1e9+7;
using P=pair<int,int>;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    ll ans=0,sum=0;
    int r=0;
    for(int l=0;l<n;l++){
        while(r<n && (sum^a[r]) == (sum+a[r]))sum+=a[r++];
        ans+=r-l;
        if(l==r)r++;
        else sum^=a[l];
    }
    cout<<ans<<endl;
    return 0;
}
