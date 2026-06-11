
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

int L;

signed main(){
    cin>>L;
    int N=20;
    vector<tuple<int,int,int>>es;

    rep(i,N-2){
        es.pb(make_tuple(N-1-(i+1),N-1-i,0));
        es.pb(make_tuple(N-1-(i+1),N-1-i,1<<i));
    }

    if(L>>19&1){
        es.pb(make_tuple(0,1,0));
        es.pb(make_tuple(0,1,1<<18));
    }

    for(int i=18;i>=0;i--){
        if(L>>i&1){
            int l=L;
            l-=l&((1<<(i+1))-1);
            es.pb(make_tuple(0,N-1-i,l));
        }
    }

    cout<<N<<" "<<es.size()<<endl;
    for(auto p:es){
        cout<<get<0>(p)+1<<" "<<get<1>(p)+1<<" "<<get<2>(p)<<endl;
    }
    return 0;
}
