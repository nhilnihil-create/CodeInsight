#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n,m;cin>>n>>m;
    vector<long long>a(n),sum(n+1);
    sum[0]=0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        sum[i+1]=a[i]+sum[i];
    }
    map<long long,long long>b;
    set<long long>c;
    for(int i=0;i<=n;++i){
        b[sum[i]%m]++;
        c.insert(sum[i]%m);
    }
    long long ans=0;
    for(auto x : c){
        ans+=b[x]*(b[x]-1)/2;
    }
    cout<<ans<<endl;
}
