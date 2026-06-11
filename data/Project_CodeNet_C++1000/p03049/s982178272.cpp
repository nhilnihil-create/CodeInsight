#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<string> S(N);
    for (int i=0;i<N;++i) cin >> S[i];
    int ans=0,cntA=0,cntB=0,cntAB=0;
    for (int i=0;i<N;++i){
        int s=S[i].size();
        for (int j=0;j+1<s;++j){
            if (S[i][j]=='A'&&S[i][j+1]=='B') ++ans;
        }
        if (S[i][0]=='B'&&S[i][s-1]=='A') ++cntAB;
        else if (S[i][0]=='B') ++cntB;
        else if (S[i][s-1]=='A') ++cntA;
    }
    if (cntAB){
        ans+=cntAB-1;
        if (cntA) ++ans,--cntA;
        if (cntB) ++ans,--cntB;
    }
    ans+=min(cntA,cntB);
    cout << ans << '\n';
}