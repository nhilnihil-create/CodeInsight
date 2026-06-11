#include<bits/stdc++.h>
using namespace std;
int main(){
  int q,z,y=0;
  cin>>q;//qはN桁の数字
  z=q;
  while(z>0){
    y = y + z % 10;//qを10で割った余り(1の位)をyに足す　最終的にf(x)になる
    z = z / 10;//f(x)を作るために桁を一つ下げてる
  }
  if(q%y==0) cout<<"Yes"<<endl;//qをyで割ると0
  else cout<<"No"<<endl;
}
