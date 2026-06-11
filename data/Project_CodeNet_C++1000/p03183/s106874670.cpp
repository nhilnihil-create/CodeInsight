#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;(i)--)
#define rrep1(i,n) for(int i=((int)(n));i>0;(i)--)
#define sz(c) ((int)(c).size())
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int> > PP;
const int MAX=1e3+10;


int N;
vi w,s;
vll v;
int S, W;

void input(){
    cin>>N;
    vi tw(N), ts(N);
    vll tv(N);
    rep(i,N){
        cin>>tw[i]>>ts[i]>>tv[i];
        S=max(S, ts[i]);
        W=max(W, tw[i]);
    }

    vector<P> seq(N);
    rep(i,N)seq[i]=mp(tw[i]+ts[i], i);
    sort(all(seq));
    rep(i,N){
        int ind=seq[i].se;
        w.pb(tw[ind]);
        s.pb(ts[ind]);
        v.pb(tv[ind]);
    }
}

ll dp[1010][20010];
ll ans;
void solve(){
    rep(i,N+1)rep(we,S+W+1)dp[i][we]=-1;
    dp[0][0]=0;
    rep(i,N)rep(we, S+W+1)if(dp[i][we]!=-1){
        dp[i+1][we]=max(dp[i+1][we], dp[i][we]);
        if(we<=s[i]) dp[i+1][we+w[i]]=max(dp[i+1][we+w[i]], dp[i][we]+v[i]);
    }
    rep(we,S+W+1)ans=max(ans, dp[N][we]);
}

void output(){
    cout<<ans;
}

int main(){
  input();
  solve();
  output();
}
