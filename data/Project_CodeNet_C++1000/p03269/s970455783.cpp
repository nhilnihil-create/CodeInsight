#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll l;
    cin>>l;
    l--;
    vector<vector<pll> >G(20);
    ll cnt=0;
    ll now=0;
    bool f=0;
    for(int i=19;i>=0;i--){
        if(f){
            G[i].pb(mp(i+1,(1<<i)));
            G[i].pb(mp(i+1,0));
            cnt+=2;
        }
        f|=((1<<i)&l);
        if((1<<i)&l){
            if(i!=19){
                G[i].pb(mp(19,now));
                cnt++;
            }
            now+=(1<<i);
        }
    }
    G[0].pb(mp(19,now));
    cnt++;
    cout<<20<<' '<<cnt<<endl;
    rep(i,19){
        for(auto e:G[i]){
            cout<<i+1<<' '<<e.first+1<<' '<<e.second<<endl;
        }
    }
}