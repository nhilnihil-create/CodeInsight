#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
string alp="abcdefghijklmnopqrstuvwxyz";

int main(){
    ll N;
    cin >> N;
    vector<ll> C(N);
    rep(i,N){
        cin >> C[i];
        C[i]--;
    }
    map<ll,ll> m;
    map<ll,ll> mc;
    vector<ll> dp(N+1);
    dp[0]=1;
    rep(i,N){
        if (!m.count(C[i])){
            dp[i+1]=dp[i];
        }
        else {
            int j=m[C[i]];
            if (j!=i){
                dp[i+1]=(dp[i]+mc[C[i]])%MOD;
            }
            else {
                dp[i+1]=dp[i];
            }
        }
        m[C[i]]=i+1;
        if (!(i>0&&C[i]==C[i-1])){
            mc[C[i]]+=dp[i];
            mc[C[i]]%=MOD;
        }
    }
    cout << dp[N] << endl;
}