#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b) {if(a>b) {a=b; return true;} return false;}
#define itn int
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sortt(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=2e9;
const ll lnf=9e18;

ll kiri(ll a,ll b){return a%b==0?a/b:a/b+1;}

int main(){
  itn n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  reverse(all(a));
  if(a[0]!=2){
    cout << -1 << endl;
    return 0;
  }
  ll l=2,r=3;
  rep(i,n){
    l=a[i]*kiri(l,a[i]);
    r=a[i]*(r/a[i])+a[i]-1;
    if(l>r){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << l << " " << r << endl;
}