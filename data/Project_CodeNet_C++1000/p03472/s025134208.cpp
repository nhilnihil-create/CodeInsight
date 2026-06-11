#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i = s;i < (int)(n);i++)
typedef long long ll;

int main(){
  int n;
  int h;
  int i,t;
  ll cnt = 0;
  ll sum = 0;
  int max = -100100100;
  int a;
  int b[100006];

  scanf("%d %d", &n, &h);

  for(i = 0;i < n;i++){
    scanf("%d %d", &a, &b[i]);

    if(max < a) max = a;
  }

  sort(b,b + n);

  for(i = n - 1;i >= 0;i--){
    if(b[i] < max) break;

    h -= b[i];
    cnt++;

    if(h <= 0) break;
  }

  if(h > 0){
    if(h % max == 0) cnt += h/max;

    else cnt += h/max + 1;
  }

  printf("%lld\n", cnt);

  return 0;
}