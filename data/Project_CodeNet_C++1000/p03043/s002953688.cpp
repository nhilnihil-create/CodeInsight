#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, k, x;
  cin>>n>>k;
  double d=1, sum=0;
  
  for(int i=1; i<n+1; i++){
    d = 1;
    x = i;
    while(x<k){
      d*=0.5;
      x*=2;
    }
    sum+=d;
  }
  double ans = sum/n;
  printf("%.10lf",ans);
}