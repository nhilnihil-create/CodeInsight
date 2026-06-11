#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  double n, k;
  cin >> n >> k;
  double ans = 0;
  for(int i=1; i<=n; i++){
    int score = i;
    double p = 1/n;
    while(score < k){
      p *= 0.5;
      score *= 2;
    }
    ans += p;
  }
  printf("%.10f\n", ans);   
}
