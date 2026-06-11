#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  int n;
  cin >> n;
  int _A = 0,B_ = 0,BA = 0;
  ll res = 0;
  rep(i,n){
    string s;cin >> s;
    if(s[0] == 'B' && s.back() == 'A'){
      BA++;
    }else if(s[0] == 'B'){
      B_++;
    }else if(s.back() == 'A'){
      _A++;
    }
    for(int j = 1;j < s.size();j++){
      if(s[j] == 'B' && s[j-1] == 'A')res++;
    }
  }
  if(BA > 0){
    res += BA-1;
    if(B_ > 0)res++,B_--;
    if(_A > 0)res++,_A--;
  }
  res += min(B_,_A);
  cout << res << endl;








  return 0;
}