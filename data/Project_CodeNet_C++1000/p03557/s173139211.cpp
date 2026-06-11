#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
using ll = long long;

int main(){
    int n;cin>>n;
    ll ans=0;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) cin>>c[i];
    sort(a.begin(),a.end());
    sort(c.begin(),c.end());
    for(int i=0;i<n;i++){
        auto iter=lower_bound(a.begin(),a.end(),b[i]);
        ll index1=iter-a.begin();
        auto it=upper_bound(c.begin(),c.end(),b[i]);
        ll index2=it-c.begin();
        ans+=index1*(n-index2);
    }
    cout<<ans<<endl;
}
