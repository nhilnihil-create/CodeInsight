#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
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
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
ll m;
vi t;
bool check(string s){
    int n=sz(s);
    int p=0;
    bool ok=true;
    m=0;
    if(s[0]!='1'){
        return false;
    }
    while(p<=(n-2)/2){
        if(s[p]!=s[n-p-2]){
            ok=false;
            break;
        }
        if(s[p]=='1'&&s[n-p-2]=='1'){
            t.pb(p+1);
            if(p!=n-p-2){t.pb(n-p-1);}
        }
        p++;
    }
    return ok;
}
int main(){
    string s;cin>>s;
    int n=sz(s);
    if(s[n-1]=='1'){
        cout<<-1<<endl;
        return 0;
    }
    if(!check(s)){
        cout<<-1<<endl;
        return 0;
    }
    vector<l_l> ans;
    ll u0=1;
    ll u,v=0;
    sort(t.begin(),t.end());
    //for(auto pp:t)cout<<111<<" "<<pp<<endl;
    rrep(i,sz(t)-1){
        if(v==0)v=u0+1;
        u=v;
        ans.pb({u0,v++});
        while(v<=t[i]){
            ans.pb({u,v++});
        }
        u0=u;
    }
    ans.pb({u0,n});
    for(auto pp:ans)cout<<pp.fi<<" "<<pp.se<<endl;
    return 0;
}