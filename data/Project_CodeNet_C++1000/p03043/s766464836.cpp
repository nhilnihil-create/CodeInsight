#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n, k;
  cin >> n >> k;
  double ans = 0;
  REP(i,1,n+1){
    double p = 1;
    int x = i;
    while (x < k){
      p /= 2;
      x *= 2;
    }
    ans += p / n;
  }
  printf("%.10f", ans);
  return 0;
}
