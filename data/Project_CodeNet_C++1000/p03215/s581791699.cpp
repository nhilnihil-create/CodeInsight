#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<long long> a(n+1,0ll);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)a[i]+=a[i-1];
    vector<long long> v;
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            v.push_back(a[j]-a[i]);
        }
    }
    //1e6個の数列が与えられるのでこの中からk個選んでsubsetをつくりそのANDを最大化する
    //上から貪欲にそのbitを立てられるか調べる
    long long res=0;
    for(long long b=60;b>=0;b--){
        vector<long long> vv;
        long long now=(1ll<<b);
        for(auto it:v)if(it&now)vv.push_back(it);
        if(vv.size()>=k){
            //cout<<b<<endl;
            res+=1ll<<b;
            v=vv;
        }
    }
    cout<<res<<endl;
}
