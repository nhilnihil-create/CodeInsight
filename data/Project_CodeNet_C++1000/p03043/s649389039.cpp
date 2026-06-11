#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;


int main(){
  ll n, k;
  cin >> n >> k;
  int count;
  double ans = 0.0;
  double a = 0.5;
  for(int i = 1; i <= n; i++){
    count = 0;
    double now = i;
    while(now <= k - 1){
      now *= 2.0;
      count++;
    }
    
    ans += pow(a, (double)count);
    
  }
  ans = ans / (double)n;
 printf("%.10lf", ans);

}
