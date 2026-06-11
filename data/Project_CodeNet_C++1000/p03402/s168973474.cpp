#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  vector<vector<char>> s(50,vector<char>(100,'#'));
  vector<vector<char>> t(50,vector<char>(100,'.'));
  int cnta=0;
  for(int i=0;i<50;i+=2){
    if(cnta==a-1){
      break;
    }
    for(int j=0;j<100;j+=2){
      if(cnta==a-1){
       break;
      }
      s[i][j]='.';
      cnta++;
    }
  }
  int cntb=0;
  for(int i=0;i<50;i+=2){
    if(cntb==b-1){
      break;
    }
    for(int j=0;j<100;j+=2){
      if(cntb==b-1){
        break;
      }
      t[i][j]='#';
      cntb++;
    }
  }
  cout << 100 << " " << 100 << endl;
  for(int i=0;i<50;i++){
    for(int j=0;j<100;j++){
      cout << s[i][j];
    }
    cout << endl;
  }
  for(int i=49;i>=0;i--){
    for(int j=0;j<100;j++){
      cout << t[i][j];
    }
    cout << endl;
  }
}