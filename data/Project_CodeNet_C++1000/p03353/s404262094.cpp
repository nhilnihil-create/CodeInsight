#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 1000000000000
#define MOD 1000000007
using ll = long long;

int main(){
  string s;
  int k;
  cin >> s >> k;
  int len = s.size();

  
  set<string> jisho;
  for(int l = 1; l <= min(k,len); l++){//長さ
    for(int i = 0; i < len-l+1; i++){
      string tmp = "";
      for(int j = 0; j < l; j++){
        tmp = tmp + s.at(i+j);
      }
      jisho.insert(tmp);
    }
  }
  int cnt = 0;
  for(auto str: jisho){
    cnt++;
    if(cnt==k){
      cout<<str<<endl;
      return 0;
    }
  }
  
  return 0;
}