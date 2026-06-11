#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
ll INF=1e12;
int main(void){
    int n;
    cin>>n;
    vector<vector<int> > f(n, vector<int>(10));
    vector<vector<int> > p(n, vector<int>(11));
    rep(i, n)rep(j, 10) cin>>f[i][j];
    rep(i, n)rep(j, 11) cin>>p[i][j];
    ll ans=-INF;
    for(int i=1;i<(1<<10);i++){
        vector<int> open(10, 0);
        rep(j, 10) {
            if((i>>j)&1) open[j]=1;
        }
        vector<ll>num(n);
        rep(j, 10){
            rep(k, n){
                if(f[k][j]&open[j]) num[k]++;
            }
        }
        ll tmp=0;
        rep(j, n) tmp+=p[j][num[j]];
        ans=max(ans, tmp);
    }
    cout<<ans<<endl;

    return 0;
}