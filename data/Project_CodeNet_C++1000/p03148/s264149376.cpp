#include<bits/stdc++.h>
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
const int inf=1e9+7;
int main(){
    ll n,k;cin>>n>>k;
    vector<vector<ll> >b(n);
    priority_queue<pll,vector<pll>,greater<pll> >small;
    priority_queue<pll>big;
    priority_queue<pll>big2;
    ll t,d;
    map<ll,ll>m;
    ll T=0;
    rep(i,n){
        cin>>t>>d;
        if(m.find(t)==m.end()){
            m[t]=T;
            T++;
        }
        b[m[t]].pb(d);
    }
    rep(j,T)sort(rall(b[j]));
    rep(j,T)big2.push(mp(b[j][0],j));
    rep(j,T)REP(i,1,b[j].size())big.push(mp(b[j][i],j));
    vector<ll>a(T);
    vector<bool>used(T);
    ll sum=0;
    ll now=min(k,T);
    rep(i,now){
        pll q=big2.top();
        big2.pop();
        sum+=q.first;
        small.push(q);
        used[q.second]=1;
        a[q.second]++;
    }
    rep(i,k-T){
        pll q=big.top();
        big.pop();
        sum+=q.first;
        a[q.second]++;
    }
    ll ma=sum+now*now;
    while(T>1){
        pll r=small.top();
        small.pop();
        if(a[r.second]>1)break;
        if(big.empty())break;
        pll q=big.top();
        if(!used[q.second])break;
        big.pop();
        a[r.second]--;
        used[r.second]=0;
        a[q.second]++;
        now--;
        sum-=r.first;
        sum+=q.first;
        ma=max(ma,sum+now*now);
    }
    cout<<ma<<endl;
}