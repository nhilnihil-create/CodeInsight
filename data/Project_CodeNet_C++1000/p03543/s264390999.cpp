#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  int num[4];
  num[0]=n/1000;
  num[1]=(n-num[0]*1000)/100;
  num[2]=(n-num[0]*1000 -num[1]*100)/10;
  num[3]=(n-num[0]*1000 -num[1]*100 -num[2]*10);
  if(num[1]==num[2] && (num[0] == num[1] || num[1] == num[3])){
  	cout << "Yes" << endl;
  }else{
  	cout << "No" << endl;
  }
}