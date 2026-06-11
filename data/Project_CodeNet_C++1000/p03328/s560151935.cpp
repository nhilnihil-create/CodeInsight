#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int a,b;
  cin >> a >> b;
  int ans;
  //差から、1本目(a)の塔の高さを求める
  int dif;
  dif=b-a;

  int height_a;
  height_a=(dif*(dif-1))/2;

  ans=height_a-a;

  cout << ans <<endl;
  return 0;
}