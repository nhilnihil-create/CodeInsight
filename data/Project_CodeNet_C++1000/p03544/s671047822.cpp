#include <bits/stdc++.h>
using namespace std;

int main() {
  long n;
  cin >> n;
  vector<long> lucasnum(n+1);
  lucasnum[0]=2,lucasnum[1]=1;
  for(long i=2;i<=n;i++) lucasnum[i]=lucasnum[i-1]+lucasnum[i-2];
  cout << lucasnum[n] << endl;
}