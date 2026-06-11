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
    ll n;cin>>n;
    vector<ll>exist(13);
    bool f=0;
    rep(i,n){
        ll d;cin>>d;
        exist[d]++;
        if(d==0||exist[d]==3||exist[12]==2)f=1;
    }
    if(f){
        cout<<0<<endl;
        return 0;
    }
    ll mi=0;
    rep(i,1<<13){
        vector<ll>a(0);
        a.pb(0);
        rep(j,13){
            if(exist[j]==2){
                a.pb(j);
                a.pb(24-j);
            }else if(exist[j]==1){
                if((1<<j)&i)a.pb(j);
                else a.pb(24-j);
            }
        }
        ll cnt=inf;
        rep(j,a.size()){
            REP(k,j+1,a.size()){
                ll D=max(a[j],a[k])-min(a[j],a[k]);
                D=min(D,24-D);
                cnt=min(cnt,D);
            }
        }
        mi=max(cnt,mi);
    }
    cout<<mi<<endl;
}