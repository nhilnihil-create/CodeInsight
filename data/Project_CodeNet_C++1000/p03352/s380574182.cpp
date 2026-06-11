#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int x;
  cin >>x;
  int curMax = 1;
  for(int i = 2; i<x; i++){
    int num = i;
    while(true){
      num *= i;
      if(x<num) break;
      if(curMax<num) curMax = num;
    }
  }
  cout << curMax << endl;
  return 0;
}