#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;


int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<P> bc(m);
  rep(i, n){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  rep(i, m){
    int b, c;
    cin >> b >> c;
    bc[i]=P(c, b);
  }
  sort(bc.begin(), bc.end(), greater<P>());
  int num=0;
  vector<int> d;
  for(int i=0; i<m && num<n; i++){
    P p=bc[i];
    rep(j, p.second){
      d.push_back(p.first);
      num++;
      if(num==n)break;
    }
  }
  ll ans=0;
  rep(i, n){
    ans+=a[i];
  }
  int dsz=min(n, (int)d.size());
  rep(i, dsz){
    if(d[i]-a[i]>0){
      ans+=d[i]-a[i];
    } else {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
