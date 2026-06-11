#include <bits/stdc++.h>

//const long long INF = 1000000001;
const int INF = 2147483647;

const long long MOD = 1000000009;

typedef long long ll;

const int max = 100000; //配列の最大長

int n;

ll search_low(ll *ls,int k){
  ll left,right;
  left = -1,right = n;

  while(right - left > 1){
    ll mid = left + (right - left) / 2;
    if(ls[mid] >= k){
      right = mid;
    } else {
      left = mid;
    }
  }

  return left+1;
}

ll search_up(ll *ls,int k){
  ll left,right;
  left = -1,right = n;

  while(right - left > 1){
    ll mid = left + (right - left) / 2;
    if(ls[mid] > k){
      right = mid;
    } else {
      left = mid;
    }
  }

  return right;
}

int main(void){
  std::cin >> n;

  ll a[n],b[n],c[n];
  for(int i=0; i<n; i++) std::cin >> a[i];
  for(int i=0; i<n; i++) std::cin >> b[i];
  for(int i=0; i<n; i++) std::cin >> c[i];

  std::sort(a,a+n); std::sort(b,b+n); std::sort(c,c+n);

  ll count = 0;
  for(int i=0; i<n; i++){
    ll temp1 = search_low(a,b[i]); //bの各値未満の数
    ll temp2 = n - search_up(c,b[i]); //bの各値超過の個数
    count += temp1 * temp2;
  }

  std::cout << count << std::endl;
  return 0;
}
