#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
 string s;
    cin >> s;
    
    long long bcount =0;
    int wcount = 0;
    int bmemo = 0;
    int wmemo = 0;
    
    // 先頭のWは寄与しないので削除しておく
    for(int i = 0;i<s.size();i++) {
        if(s.at(i) == 'W') {
         wmemo++;
        }
     if(s.at(i) == 'B') {
      break;
     }
    }
    
    //末尾のＢは寄与しないので削除しておく
    for(int i = s.size()-1; i >= 0; i--) {
     if(s.at(i) == 'B') {
      bmemo++;
     }
        if(s.at(i) == 'W'){
            break;
        }
    }
  
    //削除
    s.erase(s.size()-bmemo,bmemo);
    s.erase(0,wmemo);
    
    
    for(int i = 0; i < s.size();i++) {
     if(s.at(i) == 'B'){
      bcount++;
     }
    }
   
    //使わなかった
    for(int i = 0;i <s.size(); i++) {
     if(s.at(i) == 'W'){
      wcount++;
     }
    }
    
    long long count = 0;
   
    for(int i = s.size() -1; i >=0;i--) {
     if(s.at(i) == 'B') {
      count += s.size()-i-1;
     }
    }
    
    count -= (1+bcount-1)*(bcount-1)/2;
    cout << count;
}