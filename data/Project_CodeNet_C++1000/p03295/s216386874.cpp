#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
int vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}
int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}
int gyaku(int n){
    return modpow(n,MOD-2);
}
signed main() {
    int n,m;cin>>n>>m;
    vector<pair<int,int>>a(m);
    rep(i,m){
      cin>>a[i].second>>a[i].first;
    }
    sort(a.begin(),a.end());
    int last=a[0].first;
    int ans=1;
    rep(i,m){
      if(last<=a[i].second){
        ans++;
        last=a[i].first;
      }
    }
    cout<<ans<<endl;

}
