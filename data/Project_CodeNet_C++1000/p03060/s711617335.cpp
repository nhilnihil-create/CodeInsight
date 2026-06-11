#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()

int main(){
  int n;
  cin >> n;
  vector<int> v(n),c(n);
  rep(i,0,n) cin >> v.at(i);
  rep(i,0,n) cin >> c.at(i);
  int ans=0;
  rep(i,0,n){
      if(v.at(i)-c.at(i)>0) ans+=v.at(i)-c.at(i);
  }
  cout << ans << endl;
}