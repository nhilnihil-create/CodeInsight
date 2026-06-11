#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;

ll absa(ll a,ll b=0){
    if(a>b)return a-b;
    return b-a;
}

int main() {
    int A,B,Q;
    cin>>A>>B>>Q;
    vector<ll> s(A+2),t(B+2);
    
    s.at(0)=-1e12;
    s.at(A+1)=1e12;
    t.at(0)=-1e12;
    t.at(B+1)=1e12;
    rep(i,A){
        cin>>s.at(i+1);
    }
    rep(i,B){
        cin>>t.at(i+1);
    }
    
    rep(query,Q){
        ll x;
        cin>>x;
        ll bs,ns,bt,nt;
        int p=lower_bound(s.begin(),s.end(),x)-s.begin();
        bs=s.at(p-1);
        ns=s.at(p);
        int q=lower_bound(t.begin(),t.end(),x)-t.begin();
        bt=t.at(q-1);
        nt=t.at(q);
        ll ans=1e12;
        vector<vector<ll>> list(3,vector<ll>(2));
        list.at(0).at(0)=bs;
        list.at(0).at(1)=ns;
        list.at(1).at(0)=bt;
        list.at(1).at(1)=nt;
        list.at(2).at(0)=bs;
        list.at(2).at(1)=ns;
        
        rep(i,2)rep(j,2)rep(k,2){
            ll now=absa(x,list.at(i).at(j))+absa(list.at(i).at(j),list.at(i+1).at(k));
        //cout<<now<<endl;
            chmin(ans,now);
        }
        //cout<<bs<<" "<<ns<<" "<<bt<<" "<<nt<<endl;
        cout<<ans<<endl;
    }
}