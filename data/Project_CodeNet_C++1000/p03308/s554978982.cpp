#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
 
int main(){
    ll N; cin>>N;
    VL A(N);
    ll ans=0;
    rep(i,0,N)cin>>A[i];
    rep(i,0,N){
        rep(j,0,N){
            if(i==j)continue;
            ans=max(abs(A[i]-A[j]),ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}