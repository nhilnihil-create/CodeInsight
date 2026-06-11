#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    int a,b;
    p p[m];
    rep(i,m){
        cin>>a>>b;
        a--;
        b--;
        p[i]=make_pair(b,a);
    }
    sort(p,p+m);
    int ans=1;
    int small=p[0].first;
    rep(i,m){
        if(small<=p[i].second){
            ans++;
            small=p[i].first;
        }
    }
    
    cout<<ans<<endl;

    return 0;
}
