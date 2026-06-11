#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int main(){
  int N,M; cin >> N >> M;
  int x = M/N;
  int ans = 1;
  for(int i=1;i*i<=M;i++){
    if(M%i==0){
      int j = M/i;
      if(j<=x) ans = max(ans,j);
      if(i<=x) ans = max(ans,i);
    }
  }
  cout << ans << endl;
}