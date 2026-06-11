#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;

#define INF INT_MAX/3
#define MAX_N 1000

ll n, a, b;
int solve(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>n>>a>>b;
  if(n+1< a+b || n > a*b) return -1;
  std::vector<ll> vec;
  ll s = n-a;
  ll cur = n;
  rep(i,a){
    ll num = min(b-1,s) + 1;
    s -= num -1;
    rep(j,num) vec.pb(cur-num+1+j);
    cur -= num;
  }
  reverse(all(vec));
  rep(i,n-1) cout<<vec[i]<<" ";
  cout<<vec[n-1]<<endl;
  return 0;
}
int main(){
  if(solve() == -1) cout<<-1<<endl;
  return 0;
}
