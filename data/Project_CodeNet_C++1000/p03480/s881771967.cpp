#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size(),ans;
  char center;
  if(n % 2 == 0){
    ans = n/2;
    if(s.at(n/2) == s.at(n/2-1) && n > 2){
      center = s.at(n/2);
      char nextl = s.at(n/2-2),nextr = s.at(n/2+1);
      int left = n/2-2,right = n/2+1;
      ans++;
      while(center == nextl && center == nextr && right < n && left >= 0){
        ans++;left--;right++;
        if(right < n && left >= 0){
          nextl = s.at(left);nextr = s.at(right);
        }
      }
    }
    else if(n == 2){
      if(s.at(0) == s.at(1)){
        ans = 2;
      }
      else{
        ans = 1;
      }
    }
  }
  else{
    ans = n/2+1;
    if(n > 1){
      center = s.at(n/2);
      char nextl = s.at(n/2-1),nextr = s.at(n/2+1);
      int left = n/2-1,right = n/2+1;
      while(center == nextl && center == nextr && left >= 0 && right < n){
        ans++;left--;right++;
        if(left >= 0 && right < n){
          nextl = s.at(left);nextr = s.at(right);
        }
      }
    }
  }
  cout << ans << endl;
}