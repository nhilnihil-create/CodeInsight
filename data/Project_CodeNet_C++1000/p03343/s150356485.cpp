#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9;
const ll mod=998244353;
signed main(){
    ll n,k,q;cin>>n>>k>>q;
    vector<ll>a(n);
    vector<pll>p(n);
    rep(i,n){
        cin>>a[i];
        p[i]=mp(a[i],i);
    }
    sort(all(p));
    ll ans=p[q-1].first-p[0].first;
    set<ll>st;
    a.pb(0);
    st.insert(n);
    n++;
    rep(i,n){
        priority_queue<ll,vector<ll>,greater<ll> >pq;
        priority_queue<ll,vector<ll>,greater<ll> >qq;
        rep(j,n){
            if(st.find(j)!=st.end()){
                while(pq.size()>=k){
                    ll d=pq.top();
                    pq.pop();
                    qq.push(d);
                }
                while(!pq.empty()){
                    pq.pop();
                }
            }else{
                pq.push(a[j]);
            }
        }
        if(qq.size()>=q){
            ll mi=qq.top();
            qq.pop();
            //cout<<qq.top()<<endl;
            ll ma=qq.top();
            rep(o,q-1){
                ma=qq.top();
                //cout<<qq.top()<<endl;
                qq.pop();
            }
            while(!qq.empty()){
                qq.pop();
            }
            ans=min(ans,ma-mi);
        }else{
            break;
        }
        if(i<n-1)st.insert(p[i].second);
    }
    cout<<ans<<endl;
}