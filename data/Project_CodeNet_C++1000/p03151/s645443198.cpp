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
    vector<ll> a(n),b(n),d(n);
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    rep(i,n){
        d[i]=a[i]-b[i];
    }
    sort(d.begin(),d.end());
    ll tot=0,res=0;
    rep(i,n){
        if(d[i]>=0)break;
        res++;
        tot-=d[i];
    }
    reverse(d.begin(),d.end());
    rep(i,n){
        if(tot<=0)break;
        if(d[i]<=0)break;
        res++;
        tot-=d[i];
    }
    if(tot>0)cout<<-1<<endl;
    else cout<<res<<endl;
}