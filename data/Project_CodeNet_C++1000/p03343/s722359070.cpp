#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=1001001001001001001l;

int N,K,Q;
int A[2222];

int calc(int Y){
    vector<int>lis;
    int cur=0;
    while(cur<N){
        if(A[cur]<Y){
            cur++;continue;
        }
        int nex=cur;
        vector<int>v;
        while(nex<N&&A[nex]>=Y){
            v.pb(A[nex]);
            nex++;
        }
        sort(all(v));
        rep(i,(int)v.size()-K+1)lis.pb(v[i]);
        cur=nex;
    }
    sort(all(lis));
    if(lis.size()<Q)return INF;
    return lis[Q-1]-Y;
}

signed main(){
    cin>>N>>K>>Q;
    rep(i,N)cin>>A[i];

    int ans=INF;
    rep(i,N)chmin(ans,calc(A[i]));
    cout<<ans<<endl;
    return 0;
}
