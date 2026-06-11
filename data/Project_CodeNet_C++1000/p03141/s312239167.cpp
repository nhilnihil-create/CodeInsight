#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int N;
  cin >> N;
  vi A(N),B(N);
  vpii S(N);
  rep(i,N) {
    cin >> A[i] >> B[i];
    S[i]=make_pair(A[i]+B[i],i);
  }
  sort(S.begin(),S.end());
  reverse(S.begin(),S.end());
  ll ans=0;
  rep(i,N) {
    if(i%2) ans-=B[S[i].second];
    else ans+=A[S[i].second];
  }
  cout << ans << endl;
}