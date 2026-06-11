#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int n,k;
  cin >> n >> k;
  if((n+1)/2 >= k) puts("YES");
  else puts("NO");
  return 0;
}
