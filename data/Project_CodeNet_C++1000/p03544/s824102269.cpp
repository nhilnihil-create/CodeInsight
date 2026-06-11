#include <bits/stdc++.h>
using namespace std;

int lyuka(int i) {
  int64_t L;
  if (i==0) L=2;
  else if (i==1) L=1;
  else L = lyuka(i-1) + lyuka(i-2);
  return L;
}

int main() {
  int N;
  cin >> N;
  
  long long L[87];
  L[0] = 2LL;
  L[1] = 1LL;
  for(int i=2; i<=N; i++) L[i]=L[i-2]+L[i-1];
  cout << L[N] << endl;

  return 0;
}
