#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;

int calc(int x){
  int ret = 0;
  while(x%100==0){
    x /= 100;
    ret++;
  }
  return ret;
}

int main()
{
  int d, n;
  cin >> d >> n;

  int cnt = 0, val = 0;
  while(cnt<n){
    val++;
    if(calc(val)==d)
      cnt++;
  }

  cout << val << endl;

  return 0;
}
