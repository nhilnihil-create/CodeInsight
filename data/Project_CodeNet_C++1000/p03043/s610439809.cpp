#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

ll n,k;

double win(int i){
  double p = 1;
  while(i < k) {
    p /= 2;
    i *= 2;
  }
  return p;
}

int main(){
  cin >> n >> k;

  double ans = 0;
  for(int i = 1; i <=n; i++){
    ans += win(i)/n;
  }
  printf("%.12f\n",ans);
}
