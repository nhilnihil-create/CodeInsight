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

int d[31][31];
int c[510][510];
int cnt[4][31];

int main(){
  itn n,C; cin >> n >> C;
  rep(i,C)rep(j,C) cin >> d[i][j];
  rep(i,n)rep(j,n){
    cin >> c[i][j];
    c[i][j]--;
  }
  rep(i,n)rep(j,n){
    cnt[(i+j)%3][c[i][j]]++;
  }
  ll ans=lnf;
  rep(i,C)rep(j,C)rep(k,C)if(i!=j&&j!=k&&k!=i){
    ll sum=0;
    rep(x,C){
      sum+=d[x][i]*cnt[0][x];
      sum+=d[x][j]*cnt[1][x];
      sum+=d[x][k]*cnt[2][x];
    }
    chmin(ans,sum);
  }
  cout << ans << endl;
}