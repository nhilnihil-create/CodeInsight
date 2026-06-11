#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int S ;	
  int Y ;
  int Z ;
  cin >> S ;
  Y = S - (S/100)*100 ; //下二けたを抽出
  Z = Y - (Y/10)*10 ;  //一の位を抽出
  
  cout << (S/100) + (Y/10) + Z << endl;
}