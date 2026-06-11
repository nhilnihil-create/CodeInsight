#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const int INF=1e18;
const int MOD=1e9+7;
const int MAX_N=10000;

signed main(){
    int n;cin>>n;
    vector<int>G[n];
    REP(i,n-1){
        int a,b;cin>>a>>b;a--;b--;
        G[a].eb(b);
        G[b].eb(a);
    }
    vector<int>c(n);
    int sum=0;
    REP(i,n){
        cin>>c[i];
        sum+=c[i];
    }
    sort(c.rbegin(),c.rend());
    sum-=c[0];
    cout<<sum<<endl;
    int t[n];
    REP(i,n)t[i]=INF;
    t[0]=c[0];
    queue<int>q;
    q.push(0);
    int i=1;
    while(!q.empty()){
        int d=q.front();q.pop();
        for(auto v:G[d]){
            if(t[v]!=INF)continue;
            t[v]=c[i];
            q.push(v);
            i++;
        }
    }
    REP(i,n)cout<<t[i]<<" ";
}