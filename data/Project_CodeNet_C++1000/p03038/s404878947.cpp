#include <bits/stdc++.h>
using namespace std;
int n,m,p1,p2;
long long ans=0;
vector<pair<int,int> > v;
int main() {
    cin>>n>>m;
    for (int i=0; i<n; i++) {cin>>p1; v.push_back({p1,1});}
    for (int i=0; i<m; i++) {
        cin>>p1>>p2;
        v.push_back({p2,p1});
    }
    sort(v.begin(),v.end(),greater<pair<int,int> >());
    int cur=0;
    for (int i=0; i<n; i++) {
        if (v[i].second+cur>=n) {ans+=(((long long)(n-cur))*v[i].first); break;}
        ans+=(1LL*v[i].first*v[i].second);
        cur+=v[i].second;
    }
    cout<<ans<<'\n';
}