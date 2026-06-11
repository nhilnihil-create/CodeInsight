#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>


using namespace std;

int num(int x){
  int ret = 0;
  while (x > 0){
    ret += x%10;
    x /= 10;
  }
  return ret;
}
int main(){
  int a, b, N, i, j, k, min=1000, sa, sb;
  cin >> N;
  for (a = 1; a < N; a++){
    b = N - a;
    sa = num(a);
    sb = num(b);
    if (sa + sb < min){
      min = sa + sb;
    }
  }
  cout << min << endl;
  return 0;
}
