#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;
static const ll LOGN=55;



int main(void) {
  double N, M, d;
  cin >> N >> M >> d;
  double ans;
  if(d)
    ans=2*(N-d)/N/N*(M-1);
  else
    ans=1/N*(M-1);
  
  printf("%.9f\n", ans);
}



