#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, n, i, a = 0, b = 0;
  cin >> n >> h >> w;
  for(i = 0;i < n;i++){
    if(i + h <= n) a+=1;
  }
  for(i = 0;i < n;i++){
    if(i + w <= n) b+=1;
  }
  cout << a * b <<endl;
}