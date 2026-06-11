#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<=(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;
typedef vector<ll> vl;
typedef vector<bool> vb;
const ll INF=1LL << 60;
const ll MOD=1e9+7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x;
  cin >> x;
  int cnt=0;
  int y=x;
  while(y>1){
    y/=2;
    cnt++;
  }
  int ans=0, a=sqrt(x);
  rep1(i, a+1){
    int n=1;
    rep1(j, cnt){
      n*=i;
      if(n>x){
        n/=i;
        j=cnt;
      }
    }
    ans=max(ans, n);
  }

  cout << ans << endl;

  return 0;
}