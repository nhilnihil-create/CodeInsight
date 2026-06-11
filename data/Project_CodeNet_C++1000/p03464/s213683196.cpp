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
    ll k;cin>>k;
    vector<ll> a(k);
    rep(i,k)cin>>a[i];
    reverse(all(a));
    bool f=1;
    ll l=2,r=2;
    rep(i,k){
        if(l%a[i]==0){
            r=(r/a[i])*a[i]+a[i]-1;
        }else if(l/a[i]<r/a[i]){
            l=(l/a[i]+1)*a[i];
            r=(r/a[i])*a[i]+a[i]-1;
        }else{
            f=0;
            break;
        }
    }
    if(f)cout<<l<<' '<<r<<endl;
    else cout<<-1<<endl;
}