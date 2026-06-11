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
typedef tuple<int,int,int,int> tiiii;
const ll mod=1e9+7;
const int inf=2e9;
const ll lnf=9e18;

int g[510][510];

int main(){
  int h,w; cin >> h >> w;
  rep(i,h)rep(j,w) cin >> g[i][j];
  vector<tiiii> ans(0);
  rep(i,h)rep(j,w-1){
    if(g[i][j]%2==1){
      g[i][j]--;
      g[i][j+1]++;
      ans.push_back(tiiii(i,j,i,j+1));
    }
  }
  rep(i,h-1){
    if(g[i][w-1]%2==1){
      g[i][w-1]--;
      g[i+1][w-1]++;
      ans.push_back(tiiii(i,w-1,i+1,w-1));
    }
  }
  cout << ans.size() << endl;
  rep(i,ans.size()){
    int a,b,c,d;
    tie(a,b,c,d)=ans[i];
    cout << a+1 << " " << b+1 << " " << c+1 << " " << d+1 << endl;
  }
}