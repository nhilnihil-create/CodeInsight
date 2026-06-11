#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int64_t n,m;
  cin >> n >> m;
  int64_t ans= abs(n*m-(2*n+2*m-4));
  cout <<ans;
}
