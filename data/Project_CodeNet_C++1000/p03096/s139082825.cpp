#include <bits/stdc++.h>
#define override_rep(i, l, r, rep_, ...) rep_
#define rep2(i, n) for (int i = 0; i < n; i++)
#define rep3(i, l, r) for (int i = l; i < r; i++)
#define rep(...) override_rep(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define int long long
#ifdef DEBUG
std::ostream& dout=std::cout;
#else
std::stringstream dout;
#endif
using namespace std;
typedef pair<int, int> P;
template <typename T, typename U>
istream &operator>>(istream &in, pair<T, U> &p) {
  in >> p.first >> p.second;
  return in;
}
signed main() {
  int n,ans=1;
  cin>>n;
  vector<int> memo(200001,0);
  int b;
  cin>>b;
  memo[b]=1;
  rep(i,n-1){
    int c;
    cin>>c;
    ans=(ans+memo[c]*(b!=c))%1000000007;
    memo[c]=ans;
    b=c;
  }
  cout<<ans<<endl;
}