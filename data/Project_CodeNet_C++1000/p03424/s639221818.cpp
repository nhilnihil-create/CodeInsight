#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
 //初期化
 int i = 0;
 string text;
 bool flag = false;
 
 cin >> i;
 
 //入力検索
 while(i>0){
  cin >> text;
  if(text=="Y")flag = true;
  i--;
 }
  
 //出力
 if(flag) cout << "Four";
 else cout << "Three";
}