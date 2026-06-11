#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
  int N;
  cin >> N;
  int mini = INFINITY;
  for(int i=1; i<N; i++) {
    int a=0, b=0;
    int j = N-i;
    int x=i, y=j;
    while(x>0) {
      a += x%10;
      x /= 10;
    }
    while(y>0) {
      b += y%10;
      y /= 10;
    }
    mini = min(mini,a+b);
  }
  cout << mini << endl;
}