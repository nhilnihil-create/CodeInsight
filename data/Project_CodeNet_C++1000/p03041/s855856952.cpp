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
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  string ans = "";
  rep(i, n){
    if(i == k-1){
      if(str[i] == 'A') ans += 'a';
      if(str[i] == 'B') ans += 'b';
      if(str[i] == 'C') ans += 'c';
    }else{
      ans += str[i];
    }
  }
  cout << ans << endl;
  return 0;
}
