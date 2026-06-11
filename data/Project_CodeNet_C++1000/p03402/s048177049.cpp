#include <bits/stdc++.h>
using namespace std;
int A,B,x,y;
int Ans[41][100];

int main(){
  cin >> A >> B;
  for(int h=0;h<41;h++){
    for(int w=0;w<100;w++){
      if(h<20) Ans[h][w]=0;
      else Ans[h][w]=1;
    }
  }
  x=(A-1)/50;
  y=(A-1)%50;
  for(int i=0;i<x;i++){
    for(int j=0;j<50;j++){
      Ans[2*i][2*j]=1;
    }
  }
  for(int j=0;j<y;j++){
    Ans[2*x][2*j]=1;
  }

  x=(B-1)/50;
  y=(B-1)%50;
  for(int i=0;i<x;i++){
    for(int j=0;j<50;j++){
      Ans[2*i+21][2*j]=0;
    }
  }
  for(int j=0;j<y;j++){
    Ans[2*x+21][2*j]=0;
  }
  cout <<"41" <<" "<< "100"<<endl;
  for(int h=0;h<41;h++){
    for(int w=0;w<100;w++){
      if(Ans[h][w]==0) cout << '#';
      else cout << '.';
    }
    cout << endl;
  }
  return 0;
}
