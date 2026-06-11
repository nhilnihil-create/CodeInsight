#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_palindrome(string str){
  string rstr = str;
  reverse(str.begin(), str.end());

  return rstr == str;
}

int main(){
  string s;
  cin >> s;

  if (s.find('x') == string::npos){
    if (is_palindrome(s)) printf("0\n");
    else printf("-1\n");
  }else{
    string copys = s;
    copys.erase(remove(copys.begin(), copys.end(), 'x'), copys.end());
    if(is_palindrome(copys)){
      int m = copys.size(), ans = 0;
      int head = 0, tail = s.size() - 1;
      while(head < tail){
        if(s[head] != s[tail]){
          if(s[head]=='x') head++;
          else tail--;
          ans++;
        }else{
          head++;
          tail--;
        }
      }
      printf("%d\n", ans);
      
    }else{
      printf("-1\n");
    }
  }
}
