#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll n;cin>>n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    sort(all(a));
    ll ma=a[n-1];
    ll mi=ma;
    ll j=a[0];
    rep(i,n-1){
        if(mi>abs((ma+1)/2-a[i])){
            mi=abs((ma+1)/2-a[i]);
            j=a[i];
        }
    }
    cout<<ma<<' '<<j<<endl;
}