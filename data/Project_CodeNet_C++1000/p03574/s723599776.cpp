#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  string S = "";
  cin >> H >> W;
  for(int i=0; i<H; i++){
    string s;
    cin >> s;
    S += s;
  }
  
  for(int h = 0; h < H; h++){
    for(int w = 0; w < W; w++){
      
      int n = 0;
      int l = h * W + w;
      int top = l - W;
      int topleft = top - 1;
      int topright = top + 1;
      int left = l - 1;
      int right = l + 1;
      int bottom = l + W;
      int bottomleft = bottom - 1;
      int bottomright = bottom + 1;


      
      if(S.at(l) == '#'){
        cout << '#';
       continue;
      }
      
      if(top >= 0){
        if(topleft >= 0 && top % W != 0){
          if(S.at(topleft) == '#'){
//            cout << "topleft" << endl;
          n++;
          }
        }
        if(S.at(top) == '#'){
          
//            cout << "top" << endl;
          n++;
        }
        if(topright % W != 0){
 //         cout << '*' << topright << '*' << endl;
          if(S.at(topright) == '#'){
            
//            cout << "topright" << endl;
          n++;
          }
        }
      }
        if(left >= 0 && l % W != 0){
          if(S.at(left) == '#'){
            
//            cout << "left" << endl;
          n++;
          }
        }
        if(right < W * H && right % W != 0){
          if(S.at(right) == '#'){
            
//            cout << "right" << endl;
          n++;
          }
        }
      if(bottom < W * H){ 
        if(bottom % W != 0){
          if(S.at(bottomleft) == '#'){
//            cout << "bottomleft" << endl;
          n++;
          }
        }
//        if(bottom < W * H){
        if(S.at(bottom) == '#'){
          
//            cout << "bottom" << endl;
          n++;
        }
//        }

        if(bottomright < W * H && bottomright % W != 0){
          if(S.at(bottomright) == '#'){
            
//            cout << "bottomright" << endl;
          n++;
          }
        }
      }
      cout << n;
/*      cout << endl;
      cout << topleft << " " << top << " " << topright <<endl;
      cout << left << " " << l << " " << right <<endl;
      cout << bottomleft << " " << bottom << " " << bottomright <<endl;*/
    }
    cout << endl;
  }
  // ここにプログラムを追記
}