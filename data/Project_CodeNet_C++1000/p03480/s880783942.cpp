#include <iostream>
#include <string.h>
using namespace std;

int solve (string s, int k, string sub) {
  int sum = 0;
  for (int i = 1; i <= s.size() - k; i++) {
    if (i <= k) {
      int now = s[i] - '0';
      now = (now + sum) % 2;
      if (now == 1) {
        sum++;
        sub[i] = '1';
      }  
    }    
    else {
      if (sub[i - k] == '1') {
        sum++;  
      }  
      int now = s[i] - '0';
      now = (now + sum) % 2;
      if (now == 1) {
        sum++;
        sub[i] = '1';
      }
    }
  } 

  // sub[i] == '1'→ 0と1を回転させた.

  int first = 0; 
  for (int i = (s.size() - k); i < s.size(); i++) {
    int now = s[i] - '0';
    if (i == (s.size() - k)) {
      now = (now + sum) % 2;
      first = now;  
      if (first == 1) {
        sub[i] = '1';  
      }
      else {
        sub[i] = '0';  
      }
    }  
    else {
      if (i - k >= 1) {
        if (sub[i - k] == '1') {
          sum++;  
        }  
      }
      now = (now + sum) % 2;
      if (now == 1) {
        sub[i] = '1';  
      }
    }
  }
  // まずは，連続しているか確かめる
  bool follow = true;
  char last;
  int count = 0; 
  int num = 0;
  for (int i = s.size() - k; i <= s.size() - 1; i++) {
    if (sub[i] == '1') {
      if (k <= (i - 1)) {
        // ok  
      }    
      else {
        follow = false;  
      }
    }
  }
  if (follow) {
    return 1;  
  }
  return - 1;
}

int main () {
  string s;
  cin >> s;
  s = "a" + s;
  string sub;
  for (int i = 0; i < s.size(); i++) {
    sub = sub + "0";  
  }
  int left = 0;
  int right = s.size();
  /*
  for (int i = 1; i <= s.size() - 1; i++) {
    cout << i << " " << solve(s, i, sub) << endl;  
  }
  */
  while (left < right - 1) {
    int mid = (left + right) / 2;
    if (solve(s, mid, sub) == 1) {
      left = mid;  
    }  
    else {
      right = mid;  
    }
  }
  cout << left << endl;
  
}