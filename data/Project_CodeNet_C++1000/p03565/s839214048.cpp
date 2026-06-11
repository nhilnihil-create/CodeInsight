#include<iostream>
#include<algorithm>
#include<string>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  std::string s, T; std::cin >> s >> T;
  std::string S("{");
  for(int i = 0; i+T.size() <= s.size(); ++i) {
    std::string tmp = s;
    bool ok = true;
    for(int j = 0; j < T.size(); ++j) {
      if(s[i+j] == T[j]) continue;
      else if(s[i+j] == '?') tmp[i+j] = T[j];
      else { ok = false; break; }
    }
    if(!ok) continue;
    for(char& c: tmp) if(c == '?') c = 'a';
    if(S > tmp) S = tmp;
  }
  if(S == "{") S = "UNRESTORABLE";
  fin(S);
  return 0;
}
