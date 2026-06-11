#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> v;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        v.push_back({b,a});
    }

    sort(all(v));

    int ans=0;
    int pre=0;

    rep(i,m){
        int t=v[i].first;
        int s=v[i].second;
        if(s>=pre){
            ans++;
            pre=t;
        }
    }

    cout<<ans<<endl;
}