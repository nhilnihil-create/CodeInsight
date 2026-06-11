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
    vector<int> k(m);
    vector<int> s[15];
    rep(i,m){
        cin>>k[i];
        rep(j,k[i]){
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
        rep(j,m){
            int cnt=0;
            rep(i,k[j]){
                if(bit & 1<<s[j][i]) cnt++;
            }
            if(cnt%2!=p[j]){
                ok=false;
            }
        }
        if(ok) ans++;
    }

    cout<<ans<<endl;
}