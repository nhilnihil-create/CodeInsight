#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  int h, w, ans[50][50];
  string s[50];
  cin >> h >> w;
  for(int i = 0; i < h; i++) cin >> s[i];
   
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      int num = -1;
      ans[i][j] = num;
      if(s[i].substr(j,1)=="#") continue;
      if(i-1  >= 0 ) {
        if(j-1 >= 0) 
          if(s[i-1].substr(j-1,1)=="#") num++;
        if(s[i-1].substr(j,1)=="#") num++;
        if(j+1 < w)  
          if(s[i-1].substr(j+1,1)=="#") num++;
      }
        if(j-1 >= 0) 
          if(s[i].substr(j-1,1)=="#") num++;
        //if(s[i].substr(j,1)=="#") ans[i][j]++;
        if(j+1 < w)  
          if(s[i].substr(j+1,1)=="#") num++;
      if(i+1 < h) {
        if(j-1 >= 0) 
          if(s[i+1].substr(j-1,1)=="#") num++;
        if(s[i+1].substr(j,1)=="#") num++;
        if(j+1 < w)  
        if(s[i+1].substr(j+1,1)=="#") num++;
      }
      ans[i][j] = num+1;
    }
  }

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(ans[i][j] == -1) cout << "#";
      else cout << ans[i][j];
    }
    cout << endl;
  }
}