#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;

int main() {
  int a, b, c, k;
  cin>>a>>b>>c>>k;

  int multi = 0, tmp = 0;
  multi = max(a, b);
  tmp = min(a, b);
  int plus = tmp;

  tmp = min(multi, c);
  multi = max(multi, c);

  plus += tmp;

  int z = pow(2, k);
  multi = multi * z;

  int ans;
  ans = multi + plus;
  cout<<ans<<endl;


  return 0;
}