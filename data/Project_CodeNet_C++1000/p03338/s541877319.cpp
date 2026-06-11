#include <bits/stdc++.h>
using namespace std;

int main(){
  int  n;
  string s;
  cin >> n >> s;
  int ans =0;

  
  
  for(int i=1;i<n;i++){
      int count =0;
    for(char c='a';c<='z';c++){
    bool left = false;
    bool right = false;
    for(int j=0;j<i;j++){
      if(s[j]==c) left = true;
    }
      for(int k=i;k<n;k++){
        if(s[k]==c) right = true;
      }
      if(left&&right) count++;
    }
    ans = max(ans,count);
  }
  
  cout << ans << endl;
}
  
  

