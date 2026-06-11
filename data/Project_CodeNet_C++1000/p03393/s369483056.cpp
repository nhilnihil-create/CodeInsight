#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	int N,sw = 0,a = 0,check = 0;
  char c = 'z';
  string s,s2,s3;
  cin >> s;
  if(s.length() < 26){
    s2 = s;
    sort(s2.begin(),s2.end());
  for(char i = 'a';i <= 'z';i++){
    if(s2[a] != i){
      s += i;
      cout << s << endl;
      return 0;
    }
    a++;
  }
  }else{
    s2 = s;
  sort(s2.begin(),s2.end());
    for(int i = 26;i >= 1;i--){
        for(int j = i;j <= 26;j++){
          if(s[i - 1] < s[j - 1] && c >= s[j - 1]){
            c = s[j - 1];
            sw = 1;
          }
        }
        if(sw == 1){
          s[i - 1] = c;
            for(int k = 0;k < 26;k++){
              if(k != i){
              cout << s[k];
              }else{
                cout << endl;
                return 0;
              }
          }
        }
        }
 cout << -1 << endl;
  }
  return 0;
}