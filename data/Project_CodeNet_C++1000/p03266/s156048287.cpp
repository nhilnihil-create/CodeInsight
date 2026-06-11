#include<bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
#define int long long
signed main(){
  int N, K;
  cin >> N >> K;

  int a = N / K;
  int b = 0;
  if(K%2 == 0)b = (N+K/2) / K;

  cout << a * a * a + b * b * b;
}
