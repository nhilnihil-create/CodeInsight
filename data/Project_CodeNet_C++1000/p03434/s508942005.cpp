#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, tmp;
  int a[101];
  int alice = 0;
  int bob = 0;
  int count = 1;
  cin >> n;
  for(int i = 0; i < n; i++)cin >> a[i];
  tmp = a[0];
  for(int i = 1; i <= n; i++){
    tmp = a[0];
    for(int j = 0; j < n; j++){
      tmp = max(tmp, a[j]);
    }
    if(i % 2 != 0){
      alice += tmp;
      for(int j = 0; j < n; j++){
        if(tmp == a[j]){
          a[j] = 0;
          break;
        }
      }
    }
    else{
      bob += tmp;
      for(int j = 0; j < n; j++){
        if(tmp == a[j]){
          a[j] = 0;
          break;
        }
      }
    }
  }
  //cout <<alice <<endl << bob << endl;
  cout << alice - bob << endl;
}