#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

int main(){
  ll n,k;
  ll v[56];
  int i;
  ll sum = 0;
  int p = 0;
  int m = 0;

  scanf("%lld %lld", &n, &k);

  for(i = 0;i < n;i++){
    scanf("%lld", &v[i]);
  }

  ll limit = min(n,k);

  ll a,b;
  vector <ll> get;
  ll mx = 0;
  for(a = 0;a <= limit;a++){
    for(b = 0;b <= limit;b++){
      if(a + b > limit) break;

      if(!(get.empty())) get.clear();

      sum = 0;
      for(i = 0;i < a;i++){
        get.push_back(v[i]);
      }

      for(i = 0;i < b;i++){
        get.push_back(v[n - 1 - i]);
      }

      sort(get.begin(),get.end());

      ll t = get.size();
      ll limit2 = min(t,k - a - b);
      for(i = 0;i < limit2;i++){
        if(get[i] < 0) get[i] = 0;

        else break;
      }

      for(i = 0;i < get.size();i++){
        sum += get[i];
      }

      if(mx < sum) mx = sum;
    }
  }

  printf("%lld\n", mx);
  return 0;
}