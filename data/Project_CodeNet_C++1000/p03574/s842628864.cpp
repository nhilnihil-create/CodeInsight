#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin >> H >> W;
  //格納するstringを設定
  string Sb,Sn,Sa,Snum;
  Snum = "";
    for (int k=0; k < W; k++){
  Snum = Snum + ".";
    }
  Sn =  "." + Snum +  ".";
  cin >> Sa;
  Sa =  "." + Sa +  ".";
  // 外側に'.'を一周追加して、辺・頂点での場合分けを減らす方針
  for (int i=0; i < H; i++){
    Sb = Sn;
    Sn = Sa;
    
    string Vi;
    Vi = "";
    
    if (i == H-1){
    Sa = "." + Snum + ".";
    }else{
    cin >> Sa;
    Sa = "." + Sa + ".";
    }
    
  for (int j=0; j < W; j++){
    char A,B,C,D,E,F,G,H,I,Cn;
    A = Sb.at(j);
    B = Sb.at(j+1);
    C = Sb.at(j+2);
    D = Sn.at(j);
    E = Sn.at(j+1);
    F = Sn.at(j+2);
    G = Sa.at(j);
    H = Sa.at(j+1);
    I = Sa.at(j+2);
    
    int x=0;
    Cn = '.';      
    if (E == '#'){
    Cn = '#';
    }else{
    if (A == '#'){
    x++;
    }
      if (B == '#'){
    x++;
    }if (C == '#'){
    x++;
    }if (D == '#'){
    x++;
    }if (F == '#'){
    x++;
    }if (G == '#'){
    x++;
    }if (H == '#'){
    x++;
    }if (I == '#'){
    x++;
    }
    if (x == 0){
    Cn = '0';
    }else if (x == 1){
    Cn = '1';
    }else if (x == 2){
    Cn = '2';
    }else if (x == 3){
    Cn = '3';
    }else if (x == 4){
    Cn = '4';
    }else if (x == 5){
    Cn = '5';
    }else if (x == 6){
    Cn = '6';
    }else if (x == 7){
    Cn = '7';
    }else if (x == 8){
    Cn = '8';
    }
    }
      
      Vi = Vi + Cn;
    }
    
   cout << Vi << endl; 
  }
  
}