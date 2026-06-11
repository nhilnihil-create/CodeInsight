#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF 1e16
#define mod 1000000007

ll M,N;
vector<int> g[100000];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>M;
  N=-1;
  repl(i,1,100000){
    if(i*(i-1)/2==M){
      N=i;
      break;
    }
  }
  if(N==-1){
    cout<<"No"<<endl;
    return 0;
  }
  ll idx=0;
  rep(i,N)rep(j,i){
    g[i].push_back(idx);
    g[j].push_back(idx++);
  }
  cout<<"Yes"<<endl;
  cout<<N<<endl;
  rep(i,N){
    cout<<g[i].size();
    rep(j,g[i].size())cout<<" "<<g[i][j]+1;
    cout<<endl;
  }

  return 0;
}
