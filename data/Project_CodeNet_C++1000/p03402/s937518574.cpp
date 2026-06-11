#include<bits/stdc++.h>
using namespace std;

int main(){
  cout << 100 << ' ' << 100 << endl;
  int a,b,acount = 0,bcount = 0;
  cin >> a >> b;
  for(int i = 1;i <= 100;i++){
    for(int j = 1;j <= 100;j++){
      if(i <= 50){
        if(acount < a-1 && i % 2 == 1 && j % 2 == 1){
          cout << '.';
          acount++;
        }
        else{
          cout << '#';
        }
      }
      else{
        if(bcount < b-1 && i % 2 == 0 && j % 2 == 1){
          cout << '#';
          bcount++;
        }
        else{
          cout << '.';
        }
      }
    }
    cout << ' ' << endl;
  }
}