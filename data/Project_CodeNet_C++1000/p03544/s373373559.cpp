#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long n=2,m=1;
  for(int i=0;i<N;i++){
    m=n+m;
    n=m-n;
  }
  cout << n << endl;
}
