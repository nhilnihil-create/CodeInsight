#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll MOD = 1e9+7;
ll LLINF = 1LL << 60;
int INF = INT_MAX;

ll n,m;

ll f(int x, vector<vector<ll>> val){
        vector<ll> v(n);
        rep(i,0,3){
                if((x>>i)&1){
                        rep(j,0,n){
                                v[j]+=val[j][i];
                        }
                }else{
                        rep(j,0,n){
                                v[j]-=val[j][i];
                        }
                }
        }
        sort(all(v));
        reverse(all(v));
        ll sum=0;
        rep(i,0,m){
                sum+=v[i];
        }
        return sum;
}

int main(){
        cin>>n>>m;
        vector<vector<ll>> val(n, vector<ll>(3,0));
        rep(i,0,n){
                rep(j,0,3){
                        cin>>val[i][j];
                }
        }
        ll ans=0;
        rep(bit,0,8){
                ans=max(ans,f(bit,val));
        }
        cout<<ans<<endl;
}