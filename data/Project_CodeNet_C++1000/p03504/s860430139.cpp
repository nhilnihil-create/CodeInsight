#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define itn int
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

int d[100010][31];
int sd[100010];

int main(){
  int n,C; cin >> n >> C;
  vector<tiii> abc(n);
  rep(i,n){
    int a,b,c;
    cin >> a >> b >> c; c--;
    abc[i]=tiii(a,b,c);
  }
  sortt(abc);
  rep(i,n){
    itn a,b,c;
    tie(a,b,c)=abc[i];
    if(d[a][c]==-1) d[a][c]++;
    else d[a-1][c]++;
    d[b][c]--;
  }
  rep(i,100010)rep(j,C) sd[i]+=d[i][j];
  rep(i,100009){
    sd[i+1]=sd[i]+sd[i+1];
  }
  int ans=0;
  rep(i,100010){
    chmax(ans,sd[i]);
  }
  cout << ans << endl;
}
