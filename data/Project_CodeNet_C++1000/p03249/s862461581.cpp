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
int D[111111];

int w[111111];
int d[111111];
signed main(){
    cin>>N;
    map<int,int>uku;
    rep(i,N){
        cin>>D[i];
        uku[D[i]]=i;
    }

    fill_n(w,N,1);
    vpint lis;
    rep(i,N)lis.pb({D[i],i});
    sort(all(lis));reverse(all(lis));

    vpint ans;
    rep(i,N-1){
        int v=lis[i].se;

        int tmp=N-w[v];
        int fo=D[v]+w[v]-tmp;
        if(fo>=D[v]||uku.find(fo)==uku.end()){
            cout<<-1<<endl;
            return 0;
        }
        ans.pb({v,uku[fo]});
        w[uku[fo]]+=w[v];
        d[uku[fo]]+=d[v]+w[v];
    }

    int r=lis.back().se;
    if(D[r]!=d[r]){
        cout<<-1<<endl;
        return 0;
    }

    rep(i,ans.size())cout<<ans[i].fi+1<<" "<<ans[i].se+1<<endl;
    return 0;
}
