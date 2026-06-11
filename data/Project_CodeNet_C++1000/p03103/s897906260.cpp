#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,m;cin>>n>>m;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > que;
    rep(i,n){
        ll a,b;cin>>a>>b;
        que.push({a,b});
    }
    ll res=0;
    while(que.size()&&m>0){
        ll a=que.top().first,b=que.top().second;que.pop();
        //cout<<a<<" "<<b<<endl;
        res+=min(m,b)*a;
        m-=b;
    }
    cout<<res<<endl;
}
