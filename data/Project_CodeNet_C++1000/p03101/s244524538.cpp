#include<iostream>
using namespace std;
int main(){
  int a,b;
  int c,d;
  cin>>a>>b>>c>>d;
  
  int k=a*b;
  //kはマスの総数
  k=k-b*c;
  //これで行の分が引かれた。
  k=k-a*d;
  //これで重複している分を含む列の分が引かれた。
  k=k+c*d;
  cout<<k;
  return 0;
}
