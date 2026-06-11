#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int gcd(int a,int b) {
  if(!(a%b)) return b;
  return gcd(b,a%b);
}

int main() {
  ll N,M;
  string S,T;
  cin >> N >> M >> S >> T;
  int n=N,m=M;
  if(n<m) swap(n,m);
  ll g=gcd(n,m);
  bool flag=true;
  rep(i,g) flag&=(S[i*N/g]==T[i*M/g]);
  if(flag) cout << N*M/g << endl;
  else cout << -1 << endl;
}