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
  string str;
  cin >> str;
  if(str.length() != 26){
    vb vec(26, false);
    rep(i, str.length()) vec[str[i]-'a'] = true;
    rep(i, 26){
      if(!vec[i]){
        cout << str+(char)('a'+i) << endl;
        return 0;
      }
    }      
  }else{
    vb vec(26, false);
    for(int i=25; i>=0; i--){
      rep(j, str[i]-'a'+1, 26){
        if(vec[j]){
          string ans = "";
          rep(k, i) ans += str[k];
          cout << ans+(char)('a'+j) << endl;
          return 0;
        }
      }
      vec[str[i]-'a'] = true;
    }
    cout << -1 << endl;
    return 0;
  }
}