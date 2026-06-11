#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    rep(i,n) cin>>h[i];
    vector<int> g(n,0);

    int ans=0;
    while(1){
        bool ok=true;
        rep(i,n){
            if(g[i]!=h[i]) ok=false;
        }
        if(ok){
            cout<<ans<<endl;
            return 0;
        }

        ok=true;
        rep(i,n){
            if(g[i]!=h[i] && ok){
                g[i]++;
                ans++;
                ok=false;
            }
            else if(g[i]!=h[i]) g[i]++;
            else ok=true;
        }
    }
}

