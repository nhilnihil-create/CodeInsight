#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e10;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 




////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////

int n;vector<int> a, p;unordered_map<int,int> mp;
signed main(){
  cin>>n;int ans = 0;
  rep(i,n){
    int aa;cin>>aa;a.push_back(aa);
    mp[aa]++;
  }
  sort(a.begin(), a.end());
  p.push_back(1);
  repd(i,1,35)p.push_back(p[i-1]*2);
  for(int i = n-1;i >= 0;i--){
    if(!mp.count(a[i]) || mp[a[i]] <= 0)continue;
    mp[a[i]]--;
    rep(j,p.size()){
      if(mp.find(p[j]-a[i]) != mp.end() && mp[p[j]-a[i]]){
        mp[p[j]-a[i]]--;ans++;break;
      }
    }
  }
  cout << ans << endl;
}
