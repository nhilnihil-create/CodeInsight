#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    rep(i,n) cin>>v[i];

    int ans=0;
    rep(l,n+1){
        rep(r,n+1){
            if(l+r>n) continue;
            int rest=k-(l+r);
            if(rest<0) continue;

            vector<int> has;
            rep(i,l) has.push_back(v[i]);
            rep(i,r) has.push_back(v[n-1-i]);
            sort(all(has));

            int sm=0;
            for(auto e : has) sm+=e;
            int nn=has.size();
            rep(i,min(rest,nn)){
                if(has[i]<0) sm-=has[i];
            }
            ans=max(ans,sm);
        }
    }

    cout<<ans<<endl;
}