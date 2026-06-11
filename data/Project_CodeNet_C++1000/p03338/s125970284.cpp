#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(){
  int n;
  string s;
  cin >> n >> s;

  int max_c = 0;
  for(int i = 0; i < n; i++){
    string a = s.substr(0, i);
    string b = s.substr(i);
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    int tmp_cnt = 0;
    for(char c : a) {
      auto itr = b.find(c);
      if(itr != std::string::npos) {
        tmp_cnt++;
      }
    }
    max_c = max(max_c, tmp_cnt);
  }

  cout << max_c << endl;
  return 0;

}
