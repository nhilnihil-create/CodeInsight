#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using vc=vector<char>;
using vvc=vector<vc>;
using pii = pair<int,int>;
using pil = pair<int,ll>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

vi dig(40);
vl sum(41);
int N;
vi Kbit(40);

ll dfs(int d,int k) {
  if(Kbit[d]<k) return 0;
  else if(Kbit[d]>k) return dig[d]*(1ll<<d)+sum[d];
  else {
    int x;
    if(k) x=N-dig[d];
    else x=dig[d];
    if(d) return x*(1ll<<d)+max(dfs(d-1,0),dfs(d-1,1));
    else return x*(1ll<<d);
  }
}

int main() {
  ll K;
  cin >> N >> K;
  vl A(N);
  rep(i,N) {
    cin >> A[i];
    rep(j,40) {
      if((1ll<<j)&A[i]) dig[j]++;
    }
  }
  
  rep(i,40) {
    sum[i+1]=sum[i]+max(dig[i],N-dig[i])*(1ll<<i);
    if(K&(1ll<<i)) Kbit[i]=1;
  }
  
  cout << max(dfs(39,0),dfs(39,1)) << endl;
}