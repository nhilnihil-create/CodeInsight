#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,x= 0,y = 0,t = 0,xi,yi,ti;
  cin >> n;
  bool can = true;



  for(int i =0;i < n; i++){
    cin >> ti >> xi >> yi;
    if(ti - t < abs(xi - x) + abs(yi - y)){
      can = false;
      break;
    }

    if(((ti - t)-abs(xi - x) - abs(yi - y))%2 == 0){
      x = xi;
      y = yi;
      t = ti;
    }else{
      can = false;
      break;
    }

  }

if(can){
  cout << "Yes" << endl;
}else{
  cout << "No" << endl;
}
  return 0;
}