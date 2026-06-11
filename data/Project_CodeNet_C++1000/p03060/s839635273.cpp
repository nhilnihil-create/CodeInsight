#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vi v(n), c(n);
  rep(i ,n)cin >> v[i];
  rep(i, n)cin >> c[i];

  int ans=0;
  rep(i, n)if(v[i]>c[i])ans+=v[i]-c[i];

  cout << ans << endl;

  return 0;
}