#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int a,b;
  cin >> a >> b;
  
  int hight = 0;
  for(int i=1; i<=abs(a-b); i++){
    hight += i;
  }
  
  cout << hight-b << endl;
}