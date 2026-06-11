#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll,ll> tllll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;

ll gcd(ll a,ll b){
  if(a%b==0)
    return b;
  return gcd(b,a%b);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  vector<string> ans(t);
  rep(i,t){
    ll a,b,c,d; cin >> a >> b >> c >> d;
    bool f=1;
    if(a<b||b>d||(a%b)>c) f=0;
    if(gcd(b,d)==1&&b-c>1) f=0;
    if((c-(a%b))/gcd(b,d)*gcd(b,d)+(a%b)+gcd(b,d)<b) f=0;
    if(f) ans[i]="Yes";
    else ans[i]="No";
  }
  rep(i,t){
    cout << ans[i] << endl;
  }
}