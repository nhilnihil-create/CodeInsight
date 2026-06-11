#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;
string s;

int main(){
  cin >> s;
  string use = "";
  int n = s.size();
  for(int i=n-1;i>=0;i--) use.push_back(s.at(i));
  int s_c = 0, use_c = 0, ans = 0;
  while(!(s_c == n || use_c == n)){
    if(s.at(s_c) == use.at(use_c)){
      s_c++; use_c++;
      if(s_c == n || use_c == n) ans += abs(s_c - use_c);
    }else{
      if((s.at(s_c) != 'x' )&&(use.at(use_c) != 'x')){
        cout << -1 << endl;
        return 0;
      }
      if(s.at(s_c) == 'x'){
        s_c++; ans++;
        if(s_c == n){
          cout << -1 << endl;
          return 0;
        }
      }
      if(use.at(use_c) == 'x'){
        use_c++; ans++;
        if(use_c == n){
          cout << -1 << endl;
          return 0;
        }
      }      
    }
  }
  cout << ans/2 << endl;
}