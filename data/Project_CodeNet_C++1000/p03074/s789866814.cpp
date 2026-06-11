#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
//#define at(x,i) get<i>(x);//
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
void rle(string s,vector<char> &cha,vl &num){
    ll a=0,cnt=0;
    string t;char x=s[0];
    while(a<s.size()){
        if(x==s[a])cnt++;
        else{
            cha.pb(x);num.pb(cnt);
            x=s[a];cnt=1;
        }
        a++;
    }
    cha.pb(x);num.pb(cnt);
}
int main(){
  ll n,k;cin >> n >>k;
  string s;cin >> s;
  vector<char> cha;
  vl num;
  rle(s,cha,num);
  vl rcnt,ocnt;
  if(cha[0]=='0')rcnt.pb(0);
  rep(i,cha.size()){
    if(cha[i]=='0')ocnt.pb(num[i]);
    if(cha[i]=='1')rcnt.pb(num[i]);
  }
  if(cha[cha.size()-1]=='0')rcnt.pb(0);
  ll ans=0;
  if(ocnt.size()<=k){
    cout << n <<endl;
    return 0;
  }
  rep(i,ocnt.size()-k+1){
    ll tmp=0;
    rep(j,k){
      tmp+=rcnt[j+i];
    }
    rep(j,k){
      tmp+=ocnt[j+i];
    }
    tmp+=rcnt[k+i];
    chmax(ans,tmp);
  }
  cout << ans <<endl;
}