#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int s;
  cin >> s;
  int H , J , I ;
  H = s / 100; //sの百の位を変数Hに代入する
  s = s % 100; //sの右2桁を新しいsにする
  J = s / 10; //新しいsの十の位を変数Jに代入する
  s = s % 10; //sの右1桁を新しいsにする
  I = s; //新しいsの一の位を変数Iに代入する
 cout<< H + J + I << endl;
}