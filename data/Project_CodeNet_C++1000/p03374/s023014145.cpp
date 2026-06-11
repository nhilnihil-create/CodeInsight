#include <bits/stdc++.h>

using namespace std;

int INF=1e9;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n,c;
    cin>>n>>c;

    vector<pair<long long,long long>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }

    long long ans=0;

    vector<long long> sum1(n+1),sum2(n+1);
    sum1[0]=0;sum2[0]=0;

    for(int i=0;i<n;i++)sum1[i+1]=v[i].second;
    for(int i=0;i<n;i++)sum1[i+1]+=sum1[i];
    for(int i=0;i<n;i++)sum2[i+1]=v[n-i-1].second;
    for(int i=0;i<n;i++)sum2[i+1]+=sum2[i];

    vector<long long> f1(n+1),f2(n+1);
    f1[0]=0;f2[0]=0;

    for(int i=1;i<=n;i++){
        f1[i]=sum1[i]-v[i-1].first;
        f2[i]=sum2[i]-(c-v[n-i].first);
    }

    vector<long long> g1(n+1),g2(n+1);
    g1[0]=0;g2[0]=0;

    for(int i=1;i<=n;i++){
        g1[i]=max(g1[i-1],f1[i]);
        g2[i]=max(g2[i-1],f2[i]);
    }

    for(int i=1;i<=n;i++){
        f1[i]-=v[i-1].first;
        f2[i]-=(c-v[n-i].first);
    }

    for(int i=0;i<=n;i++){
        ans=max(ans,f2[i]+g1[n-i]);
        ans=max(ans,f1[i]+g2[n-i]);
    }

    cout<<ans<<endl;

}