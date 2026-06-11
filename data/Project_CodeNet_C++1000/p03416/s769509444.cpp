#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B;
  cin >> A >> B;
  int ans = 0;
  for(int i = A; i < B+1; i++){
    string s;
    s = to_string(i);
    int s_n = s.size();
    int s_char = s.size()-1;
    int x = s_n/2-1;
    while(x  >= 0){
      char s1 = s.at(x);
      char s2 = s.at(s_char - x );
      if(s1 != s2){
        break;
      }
      if(x == 0){
        ans++;
        break;
      }
      x = x-1;
    }
  }
  cout << ans << endl;
}