#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repn(i,n) for(ll i=0;i<=(ll)(n);i++)
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
//cin.tie(0);
//ios::sync_with_stdio(false);



signed main(){
    db n,ans=0;cin>>n;
    vector<pair<db,db> > v(n+2,{0,0});//time,velocity
    for(int i=1;i < n+1;i++)
    {
        cin>>v[i].fi;
        v[i].fi+=v[i-1].fi;
    }
    for(int i=1;i < n+1;i++)
    {
        cin>>v[i].se;
    }
    
    v[n+1].fi=v[n].fi;

    db prev=0;
    for(db t=0.5;t <= v[n+1].fi;t+=0.5)
    {
        db nowv=INF;
        for(int i=n+1;1 <= i;i--)
        {
            if(t<=v[i].fi)nowv=v.at(i).se;//制限速度
        }

        for(int i=0;i < n+1;i++)
        {
            if(t>v[i].fi)nowv=min(nowv,t-v[i].fi+v.at(i).se);
            else nowv=min(nowv,v[i].fi -t +v.at(i+1).se);//バグらせた
        }
        ans+=(prev+nowv)/4; //cout<<t<<":"<<nowv<<endl;
        prev=nowv;
    }

    cout<<setprecision(10)<<ans<<endl;
}