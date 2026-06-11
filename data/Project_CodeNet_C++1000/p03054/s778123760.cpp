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
    ll h,w,n;cin>>h>>w>>n;
    ll x,y;cin>>x>>y;
    string s,t;cin>>s>>t;
    reverse(all(s));
    reverse(all(t));
    bool f=1;
    ll l=0,r=0;
    rep(i,n){
        if(r+l==w)f=0;
        if(t[i]=='L'){
            r=max(r-1,0LL);
        }
        if(t[i]=='R'){
            l=max(l-1,0LL);
        }
        if(s[i]=='L'){
            l++;
        }
        if(s[i]=='R'){
            r++;
        }
    }
    if(l>=y||y>=w+1-r)f=0;
    ll u=0,d=0;
    rep(i,n){
        if(u+d==h)f=0;
        if(t[i]=='U'){
            d=max(d-1,0LL);
        }
        if(t[i]=='D'){
            u=max(u-1,0LL);
        }
        if(s[i]=='U'){
            u++;
        }
        if(s[i]=='D'){
            d++;
        }
    }
    if(u>=x||x>=h+1-d)f=0;
    cout<<(f?"YES":"NO")<<endl;
}