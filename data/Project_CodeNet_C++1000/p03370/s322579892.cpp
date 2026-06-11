#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  int m=1000;
  for(int i=0;i<N;i++){
    int a;
    cin >> a;
    X -= a;
    if(m>a) m=a;
  }
  int a=X/m;
  cout << a+N << endl;
}
