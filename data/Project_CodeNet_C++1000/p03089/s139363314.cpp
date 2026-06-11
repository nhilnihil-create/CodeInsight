#include <bits/stdc++.h>
using namespace std;
typedef bool boool;
typedef long long ll;
#define vl vector<ll>
#define vb vector<boool>
#define vs vector<string>
#define vp vector<pair<ll, ll>>
#define vvl vector<vector<ll>>
#define vvp vector<vector<pair<ll, ll>>>
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define rep1(i, n) for (long long i=0; i<(long long)(n); i++)
#define rep2(i, s, e) for (long long i=(s); i<(long long)(e); i++)
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)

int main(){
  int n;
  cin >> n;
  vector<int> vec(n);
  rep(i, n) cin >> vec[i];
  vector<int> ans;
  for(int i=n-1; i>=0; i--){
    int index;
    rep(j, i+1){
      if(vec[j] > i+1){
        cout << -1 << endl;
        return 0;
      }
      if(vec[j] == j+1){
        index = j;
      }
    }
    ans.push_back(vec[index]);
    vec.erase(vec.begin() + index);
  }
  reverse(all(ans));
  rep(i, n) cout << ans[i] << endl;
  return 0;
}
  
  