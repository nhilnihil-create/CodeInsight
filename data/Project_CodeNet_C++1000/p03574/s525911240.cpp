#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int h, w;
  cin >>h >>w;
  
  vector<string> s(h);
  for (int i = 0; i < h; i++)
    cin >> s[i];
  
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '.') {
        int count = 0;
        //左
        if (j != 0) {
          if (s[i][j-1] == '#')
            count ++;
        } 
        //右
        if (j != w-1) {
          if (s[i][j+1] == '#')
            count ++;
        }
        //左上
        if (j != 0 && i != 0) {
          if (s[i-1][j-1] == '#')
            count ++;
        }
        //上真ん中
        if (i != 0) {
          if (s[i-1][j] == '#')
            count ++;
        }
        //右上
        if (j != w-1 && i != 0) {
          if (s[i-1][j+1] == '#')
            count ++;
        }
        //左下
        if (j != 0 && i != h-1) {
          if (s[i+1][j-1] == '#')
            count ++;
        }
        //下真ん中
        if (i != h-1) {
          if (s[i+1][j] == '#')
            count ++;
        }
        //右下
        if (j != w-1 && i != h-1) {
          if (s[i+1][j+1] == '#')
            count ++;
        }
        
        s[i][j] = '0' + count;
      }
    }
  }
  
  for (int i = 0; i < h; i++)
    cout << s[i] << endl;
  
}