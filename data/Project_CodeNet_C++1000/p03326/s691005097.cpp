#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, M;
  cin>>N>>M;
  ll X, Y, Z;
  vector<ll> score1(N), score2(N), score3(N), score4(N), score5(N), score6(N), score7(N), score8(N);
  for(int i=0;i<N;++i) {
    cin>>X>>Y>>Z;
    score1[i] = X+Y+Z;
    score2[i] = X+Y-Z;
    score3[i] = X-Y-Z;
    score4[i] = X-Y+Z;
    score5[i] = -X+Y+Z;
    score6[i] = -X+Y-Z;
    score7[i] = -X-Y-Z;
    score8[i] = -X-Y+Z;
  }
  sort(score1.begin(), score1.end(), greater<ll>());
  sort(score2.begin(), score2.end(), greater<ll>());
  sort(score3.begin(), score3.end(), greater<ll>());
  sort(score4.begin(), score4.end(), greater<ll>());
  sort(score5.begin(), score5.end(), greater<ll>());
  sort(score6.begin(), score6.end(), greater<ll>());
  sort(score7.begin(), score7.end(), greater<ll>());
  sort(score8.begin(), score8.end(), greater<ll>());
  ll ans = -1;
  ll tmp;
  tmp = 0;
  for(int i=0;i<M;++i) {
    tmp += score1[i];
  }
  ans = max(ans, tmp);
  tmp = 0;
  for(int i=0;i<M;++i) {
    tmp += score2[i];
  }
  ans = max(ans, tmp);
  tmp = 0;
  for(int i=0;i<M;++i) {
    tmp += score3[i];
  }
  ans = max(ans, tmp);
  tmp = 0;
  for(int i=0;i<M;++i) {
    tmp += score4[i];
  }
  ans = max(ans, tmp);
  tmp = 0;
  for(int i=0;i<M;++i) {
    tmp += score5[i];
  }
  ans = max(ans, tmp);
  tmp = 0;
  for(int i=0;i<M;++i) {
    tmp += score6[i];
  }
  ans = max(ans, tmp);
  tmp = 0;
  for(int i=0;i<M;++i) {
    tmp += score7[i];
  }
  ans = max(ans, tmp);
  tmp = 0;
  for(int i=0;i<M;++i) {
    tmp += score8[i];
  }
  ans = max(ans, tmp);
  cout<<ans<<endl;
}

