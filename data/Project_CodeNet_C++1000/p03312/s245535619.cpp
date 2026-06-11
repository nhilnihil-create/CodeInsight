#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
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
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n;cin>>n;
    vector<ll>a(n+1);
    ll ma=0;
    rep(i,n){
        ll b;cin>>b;
        a[i+1]=a[i]+b;
        ma+=b;
    }
    REP(i,3,n){
        ll x,y,w,z;
        ll r=i-1,l=0;
        while(r-l>1){
            ll k=(r+l)/2;
            if(a[k]<=a[i-1]-a[k])l=k;
            else r=k;
        }
        if(a[r]-(a[i-1]-a[r])<a[i-1]-a[l]-a[l]){
            x=a[r];
            y=(a[i-1]-a[r]);
        }else{
            x=a[i-1]-a[l];
            y=a[l];
        }
        r=n,l=i-1;
        while(r-l>1){
            ll k=(r+l)/2;
            if(a[k]-a[i-1]<a[n]-a[k])l=k;
            else r=k;
        }
        if(a[r]-a[i-1]-(a[n]-a[r])<a[n]-a[l]-(a[l]-a[i-1])){
            w=a[r]-a[i-1];
            z=(a[n]-a[r]);
        }else{
            w=a[n]-a[l];
            z=a[l]-a[i-1];
        }
        ma=min(ma,max(x,w)-min(y,z));
    }
    cout<<ma<<endl;
}