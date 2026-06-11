#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,O,P,Q,Z;
  Z=0;
  cin >> N;
  O=N;
  P=N;
  N %=10;//1桁目
  P /=10;
  Q=P;
  Z +=N;//代入
  P %=10;//2桁目
  Q /=10;
  Z +=P;//代入
  Q %=10;//3桁目
  Z +=Q;//代入
  cout << Z <<endl;
}