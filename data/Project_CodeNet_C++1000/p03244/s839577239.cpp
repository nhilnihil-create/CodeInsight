#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n;
    cin>>n;
    vector<int> V(n);
    rep(i,n) cin>>V[i];

    map<int,int> cnt[2];
    rep(i,n) cnt[i%2][V[i]]++;

    vector<pair<int,int>> v[2];
    rep(i,2){
        for(auto p : cnt[i]) v[i].push_back({p.second,p.first});
        sort(all(v[i]));
        reverse(all(v[i]));
    }

    if(v[0][0].second!=v[1][0].second){
        int ans=n-v[0][0].first-v[1][0].first;
        cout<<ans<<endl;
        return 0;
    }

    if(v[0].size()==1 && v[1].size()==1){
        int ans=n/2;
        cout<<ans<<endl;
        return 0;
    }

    int ans=INF;
    if(2<=v[0].size()) ans=min(ans,n-v[0][1].first-v[1][0].first);
    if(2<=v[1].size()) ans=min(ans,n-v[0][0].first-v[1][1].first);

    cout<<ans<<endl;
}