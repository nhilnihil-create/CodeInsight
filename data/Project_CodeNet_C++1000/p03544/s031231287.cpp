#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  ll r;
  ll L[2];
  cin >> N;
  
  if(N == 0)
  {
    cout << 2;
    return 0;
  }
  if(N == 1)
  {
    cout << 1;
    return 0;
  }
  L[0] = 2;
  L[1] = 1;
  for(int i = 2; i < N+1; i++)
  {
    r = L[1] + L[0];
    L[0] = L[1];
    L[1] = r;
  }
  cout << r;

}
