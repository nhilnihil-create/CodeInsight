#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)n);i++)
typedef pair<int,int> P;
using ll = long long;
const int INF=1e9;

int main(){
    int n,m,ans=0;
    cin>>n>>m;
    vector<int> s[m];
    vector<int> p(m);
    rep(i,m){
        int a;
        cin>>a;
        rep(j,a){
            int b;
            cin>>b;
            b--;
            s[i].push_back(b);
        }
    }
    rep(i,m) cin>>p[i];
    rep(biti,1<<n){
        int cnt=0;
        rep(i,m){
            int sum=0;
            rep(j,s[i].size()){
                if(biti>>s[i][j]&1) sum++;
            }
            if(sum%2==p[i]) cnt++;
        }
        if(cnt==m) ans++;
    }
    cout<<ans;
}