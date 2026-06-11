//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll n,k,ans=0; cin>>n>>k;
    ll cnt=k;
    set<ll> c;
    vector<pair<ll,ll>> v(n);
    rep(i,n){
        ll t,d; cin>>t>>d;
        v[i]=mk(d,t);
    }
    sort(al(v)); reverse(al(v));
    vector<vector<ll>> sushi(n+1);
    rep(i,k){
        ans+=v[i].first;
        c.insert(v[i].second);
        sushi[v[i].second].push_back(v[i].first);
    }
    vector<ll> l;
    rep(i,n+1){
        if((ll)sushi[i].size()<=1) continue;
        sort(al(sushi[i]));
        rep(j,(ll)sushi[i].size()-1){
            l.push_back(sushi[i][j]);
        }
    }
    if((ll)l.size()>0) sort(al(l));
    ans+=c.size()*c.size();
    ll cnt2=0,cur=ans;
    while(cnt<n){
        if(c.count(v[cnt].second)){
            cnt++; continue;
        }
        else{
            if(cnt2==(ll)l.size()) break;
            c.insert(v[cnt].second);
            cur-=l[cnt2];
            cnt2++;
            cur+=v[cnt].first;
            cur+=c.size()*2-1;
            cnt++;
            ans=max(ans,cur);
        }
    }
    cout<<ans<<endl;
}