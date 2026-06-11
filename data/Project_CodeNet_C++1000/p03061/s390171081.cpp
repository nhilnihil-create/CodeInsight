#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int gcd(int a, int b) {
  if(b==0) return a;
  if(!(a%b)) return b;
  return gcd(b, a%b);
}

int main() {
  int N;
  cin >> N;
  vi A(N);
  rep(i,N) cin >> A[i];
  
  vi g1(N),g2(N);
  rep(i,N-1) {
    int x=A[i],y=g1[i];
    if(x<y) swap(x,y);
    g1[i+1]=gcd(x,y);
    x=A[N-i-1],y=g2[i];
    if(x<y) swap(x,y);
    g2[i+1]=gcd(x,y);
  }
  
  int ans=0;
  rep(i,N) ans=max(ans,gcd(g1[i],g2[N-i-1]));
  
  cout << ans << endl;
}