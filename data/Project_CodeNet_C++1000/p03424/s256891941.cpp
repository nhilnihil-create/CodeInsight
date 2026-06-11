#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,flag;
  cin >> N;
  flag=0; //変数flagが1である時,ひなあられの種類は4種類である。
  for(int i=0;i<N;i++){
    string color; //ひなあられの色
    cin >> color;
    if(color=="Y")flag=1;
  }
  if(flag==1)cout << "Four" << endl;
  else cout << "Three" << endl;
}