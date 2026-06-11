#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h, w;
  cin >> h >> w;
  
  string prev, s, next;
  int a;
  char b;
  
  for (int i = 0; i < h; i++) {
    
    if (i == 0) {
      cin >> s;
      if (h > 1) {
        cin >> next;
      }
    }
    else if (i != h - 1) {
      cin >> next;
    }
    
    for (int j = 0; j < w; j++, a = 0) {
      
      if (s.at(j) != '#') {
      
        //左
        if (j != 0) {
          if (s.at(j - 1) == '#') {
            a++;
          }
        }
        //右
        if (j != w - 1) {
          if (s.at(j + 1) == '#') {
            a++;
          }
        }   

        //上の行
        if (i != 0) {
          //左上
          if (j != 0) {
            if (prev.at(j - 1) == '#') {
              a++;
            }
          }
          //上
          if (prev.at(j) == '#') {
            a++;
          }
          //右上
          if (j != w - 1) {
            if (prev.at(j + 1) == '#') {
              a++;
            }
          } 
        }
      
        //下の行
        if (i != h - 1) {
           //左下
          if (j != 0) {
            if (next.at(j - 1) == '#') {
              a++;
            }
          }
          //下
          if (next.at(j) == '#') {
            a++;
          }
          //右下
          if (j != w - 1) {
            if (next.at(j + 1) == '#') {
              a++;
            }
          } 
        }
        
        b = '0' + a;
        s.at(j) = b;
      }
          
    }
    
    cout << s <<endl;
    
    prev = s;
    s = next;
  }
  
}