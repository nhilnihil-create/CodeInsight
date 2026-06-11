#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i,n) for(int i=0; i<n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL

int main(){
  int n,k; cin >> n >> k;
  double ans = 0.0;
  for (int i=1; i<=n; i++){
    double tmp = 1.0/n;
    int now = i;
    while(now < k){
      now *= 2;
      tmp /= 2;
    }
    ans += tmp;
  }
  cout << setprecision(10) << ans << endl;
}