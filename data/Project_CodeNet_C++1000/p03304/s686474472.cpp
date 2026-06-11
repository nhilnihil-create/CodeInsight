#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main(){
  double n, m, d;
  cin >> n >> m >> d;
  m--;
  if (d == 0) {
    printf("%.12f\n", 1.0 / n * m);
  } else {
    double t = 2.0 * (n - d) / (n * n);
    printf("%.12f\n", t * m);
  }
  return 0;
} 