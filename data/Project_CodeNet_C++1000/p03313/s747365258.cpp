
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

int N;
int A[1<<18];

vpint ma[1<<18];

signed main(){
    cin>>N;
    rep(i,1<<N)cin>>A[i];

    rep(i,1<<N)ma[i].pb({A[i],i});
    rep(i,1<<N){
        rep(j,N)if(i>>j&1){
            vpint uku;
            for(auto p:ma[i])uku.pb(p);
            for(auto p:ma[i^(1<<j)])uku.pb(p);
            sort(all(uku));uku.erase(unique(all(uku)),uku.end());
            ma[i].clear();
            ma[i].pb(uku[uku.size()-1]);
            ma[i].pb(uku[uku.size()-2]);
        }
    }

    for(int i=1;i<(1<<N);i++){
        int ans=0;
        rep(j,N)if(i>>j&1){
            int b=i;
            b^=1<<j;
            b|=((1<<j)-1);
            if(ma[b].size()>1)chmax(ans,ma[b][0].fi+ma[b][1].fi);
        }
        chmax(ans,ma[i][0].fi+ma[i][1].fi);
        cout<<ans<<endl;
    }
    return 0;
}
