#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)a[i]+=a[i-1];
    vector<int> v;
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            v.push_back(a[j]-a[i]);
        }
    }
    int res=0;
    for(int b=60;b>=0;b--){
        int cnt=0;
        int now=(1ll<<b);
        for(auto it:v)if(it&now)cnt++;
        if(cnt>=k){
            res+=now;
            vector<int> vv;
            for(auto it:v){
                if(it&now){
                    vv.push_back(it);
                }
            }
            v=vv;
        }
    }
    cout<<res<<endl;
}
