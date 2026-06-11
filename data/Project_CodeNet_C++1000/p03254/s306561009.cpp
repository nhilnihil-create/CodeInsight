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

int main() {
  int N,x;
  cin >> N >> x;
  vi a(N);
  rep(i,N) cin >> a[i];
  sort(a.begin(),a.end());
  
  int sum=0,ans=N;
  rep(i,N) {
    sum+=a[i];
    if(sum>x) {
      ans=i;
      break;
    }
  }
  if(ans==N&&sum<x) ans--;
  
  cout << ans << endl;
}