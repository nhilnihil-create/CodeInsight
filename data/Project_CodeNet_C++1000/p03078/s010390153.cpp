#include <bits/stdc++.h>
using namespace std;
#define _overload3(_1,_2,_3,_4,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n,s) for (int i=a;s>0?i<n:i>n;i+=s)
#define rep(...) _overload3(__VA_ARGS__,per,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
const int inf = 1e9+10, mod = 1e9+7; const long long llinf = 1e18;
// head


int main(){
  int x,y,z,k;
  cin >> x >> y >> z >> k;
  vector<long long> A(x),B(y),C(z);
  rep(i,x)cin >> A[i];
  rep(i,y)cin >> B[i];
  rep(i,z)cin >> C[i];
  vector<long long >data;
  rep(i,x)rep(j,y) data.push_back(A[i]+B[j]);
  sort(all(data));
  reverse(all(data));
  vector<long long > ans;
  rep(i,min(int(data.size()),k))rep(j,z) ans.push_back(data[i]+C[j]);
  sort(all(ans));
  reverse(all(ans));
  rep(i,k) cout << ans[i] << endl;
  
}