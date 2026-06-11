#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int) n; i++)
using ll = long long;
template <class T>
using vt = std::vector<T>;
using vvi = std::vector<vt<int>>;

int main(){
  std::string s;
  std::cin >> s;

  std::string key = "keyence";
  int cnt = 7;
  rep(i,s.size()) {
    if(s[i] == key[7-cnt])  cnt--;
    else{
      for(int j = s.size()-cnt; j < s.size(); j++){
        if(s[j] != key[7-cnt]){
          std::cout << "NO" << '\n';
          return 0;
        }
        else{
          cnt--;
          if(cnt == 0)
            break;
        }
      }
    }
    if(cnt == 0)
      break;
  }

  std::cout << "YES" << '\n';
  return 0;
}
