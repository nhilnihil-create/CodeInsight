#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,x,y,flag; //flagが1ならばYes
  flag=0;
  cin >> N;
  x = N/1000;
  if(x==N/100-x*10){
    if(x==N/10-x*100-x*10)flag=1;
  }
  else {
    y = N/100 -x*10;
    if(y==N/10-x*100-y*10){
      if(y==N - (N/10)*10)flag=1;
    }
  }
  if(flag==1)cout << "Yes" << endl;
  else cout << "No" << endl;
}