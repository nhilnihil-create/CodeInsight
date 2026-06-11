#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<long long> a(n+1,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)a[i]+=a[i-1];
    vector<long long> v;
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            v.push_back(a[j]-a[i]);
        }
    }
    long long res=0;
    for(int bit=45;bit>=0;bit--){
        int cnt=0;
        int m=v.size();
        for(int i=0;i<m;i++){
            if(v[i]&(1ll<<bit))cnt++;
        }
        if(cnt>=k){
            res+=(1ll<<bit);
            vector<long long> vv;
            for(int i=0;i<m;i++){
                if(v[i]&(1ll<<bit))vv.push_back(v[i]);
            }
            v=vv;
        }
    }
    cout<<res<<endl;
}
