#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n,k;
  cin >>n >>k;
  int H = (n+k-1)/k;
  int h = n/k;
  cout << H-h << endl;
  return 0;
}
