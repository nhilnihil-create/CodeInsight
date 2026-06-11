#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);
int main() {
double n,k;
cin >> n >> k;
double ans = 0;
for(double i = 1; i <= n; i++){
  double t = i;
  double cnt = 0;
  while(t < k){
    t*=2;
    cnt++;
  }
  ans += 1/n*pow(0.5,cnt);
}
printf("%.10f\n",ans);
} 