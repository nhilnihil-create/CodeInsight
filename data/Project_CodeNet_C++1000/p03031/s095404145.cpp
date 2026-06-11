#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> s(m);
    rep(i,m){
        int k;
        cin>>k;
        rep(j,k){
            int ss;
            cin>>ss;
            ss--;
            s[i].push_back(ss);
        }
    }
    vector<int> p(m);
    rep(i,m) cin>>p[i];

    int ans=0;
    rep(bit,1<<n){
        bool ok=true;
        rep(i,m){
            int cnt=0;
            rep(j,s[i].size()){
                int x=s[i][j];
                if(bit & 1<<x) cnt++;
            }
            if(cnt%2!=p[i]) ok=false;
        }
        if(ok) ans++;
    }

    cout<<ans<<endl;
}
