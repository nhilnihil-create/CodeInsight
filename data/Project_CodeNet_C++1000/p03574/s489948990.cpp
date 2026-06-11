#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  string pre, cur, next;
  cin >> cur;
  for( int i=0; i<H; i++ ){
    cin >> next;
    for( int j=0; j<W; j++ ){
      if( cur.at(j) == '#' ){
        cout << '#';
        continue;
      }
      
      int num = 0;
      if( j != 0 ){
        if( (i != 0) && (pre.at(j-1) == '#') ){
          num++;
        }
        if( cur.at(j-1) == '#' ){
          num++;
        }
        if( (i != (H-1)) && (next.at(j-1) == '#') ){
          num++;
        }
      }
      
      if( (i != 0) && (pre.at(j) == '#') ){
        num++;
      }
      if( cur.at(j) == '#' ){
        num++;
      }
      if( (i != (H-1)) && (next.at(j) == '#') ){
        num++;
      }
      
      if( j != (W - 1) ){
        if( (i != 0) && (pre.at(j+1) == '#') ){
          num++;
        }
        if( cur.at(j+1) == '#' ){
          num++;
        }
        if( (i != (H-1)) && (next.at(j+1) == '#') ){
          num++;
        }
      }
      
      cout << num;
    }
    cout << endl;
    
    pre = cur;
    cur = next;
  }
}
