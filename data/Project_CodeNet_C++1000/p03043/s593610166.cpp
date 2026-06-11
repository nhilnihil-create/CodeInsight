#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,b) for (ll i=a;i<=ll(b);i++)
using namespace std;

ld time_multi(int,int);

ll ctoi(const char c){if('0'<=c&&c<='9') return (c-'0');return -1;}
#define ALL(x) begin(x),end(x)
  
int main(){
  ll n,k;
  cin >> n >> k;
  ld ans = 0;
  for(int i = 1; i <= n; i++){
    ld tmp = (ld)1/n * pow((ld)0.5,time_multi(i,k));
    ans += tmp;
  }
  cout << setprecision(30) << ans << endl;
}

ld time_multi(int i, int k){
  ll num = i;
  ld time = 0.0;
  while(num<k){
    num *= 2;
    time++;
  }
  return time;
}
    