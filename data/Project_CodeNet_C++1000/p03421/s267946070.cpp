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
const ll mod=1e9+7;
int main(){
    ll n,a,b;cin>>n>>a>>b;
    if(a*b<n||a+b>n+1){
        cout<<-1<<endl;
        return 0;
    }
    vector<ll>ans(0);
    ll re=n-b;
    ll now=n;
    rep(i,b){
        ll mi=min(a-1,re);
        rep(j,mi+1){
            ans.pb(now-mi+j);
        }
        re-=mi;
        now-=mi+1;
    }
    rep(i,n){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}