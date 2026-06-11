#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  double n, k, ans=0.0;
  cin >> n >> k;
  for(int i=1; i<=int(n); i++){
    double tmp = 1 / n;
    double m = double(i);
    while(m<k){
      m*=2;
      tmp *= 0.5;
    }
    ans += tmp;
  }
  printf("%.15lf\n", ans);
  return 0;
}
