#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int a,b,c;
  cin >>a >>b >>c;
  int sum = a+b+c;
  int M = max(a,max(b,c));
  int dis = 3*M - sum;
  int cnt = 0, modsum = sum;
  for(int i = 0;;i++){
    if(modsum%3==0 && modsum-sum>=dis) {
      break;
    }
    modsum += 2;
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}