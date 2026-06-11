#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a=111;
  for(int i=0;i<9;i++){
    if(n<=a){cout << a << endl;break;}
    a+=111;
  }
}