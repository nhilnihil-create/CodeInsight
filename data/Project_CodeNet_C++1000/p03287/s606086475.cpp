#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;
const ll INF = 1e+18;

int main(){
    int N,M;
    map<ll,int> mod;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    ll m=0;
    ll sum=0;
    ll ans=0;
    rep(i,N){
        sum+=A[i]%M;
        sum%=M;
        if(sum==0) ans++;
        if(mod.count(sum)) ans+=mod[sum];
        mod[sum]++;
    }

    cout << ans << endl;
}
