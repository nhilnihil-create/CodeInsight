#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    vector<ll>sum(n);
    rep(i,n)cin>>a[i];
    sum[0]=a[0];
    for(int i=1; i<n; ++i)sum[i]=sum[i-1]+a[i];
    vector<ll>v;
    for(int l=0; l<n; ++l){
        for(int r=l; r<n; ++r){
            ll x=sum[r];
            if(l!=0)x-=sum[l-1];
            v.push_back(x);
        }
    }
    int N=v.size(),bit=60;
    ll ans=0;
    vector<bool>ok(N,true);
    for(int bit=60; bit>=0; --bit){
        ll judge=1LL<<bit;
        int cnt=0;
        rep(i,N){
            if(ok[i]){
                if(v[i]&(1LL<<bit))cnt++;
            }
        }
        if(cnt>=k){
            ans+=judge;
            rep(i,N){
                if(!(v[i]&(1LL<<bit)))ok[i]=false;
            }
        }
    }
    cout<<ans<<endl;
}