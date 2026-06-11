#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n;cin>>n;
    vector<vector<ll>> t(n);
    rep(i,n-1){
        ll a,b;cin>>a>>b;a--;b--;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    priority_queue<ll> que1;
    ll res=0;
    vector<ll> c(n);
    rep(i,n){
        cin>>c[i];
        que1.push(c[i]);
    }
    sort(c.begin(),c.end());
    rep(i,n-1)res+=c[i];
    cout<<res<<endl;
    queue<ll> que2;que2.push(0);
    vector<ll> d(n,-1);
    while(que2.size()){
        ll x=que2.front();que2.pop();
        ll y=que1.top();que1.pop();
        d[x]=y;
        rep(i,t[x].size()){
            ll z=t[x][i];
            if(d[z]!=-1)continue;
            que2.push(z);
        }
    }
    rep(i,n)cout<<d[i]<<" ";
    cout<<endl;
}