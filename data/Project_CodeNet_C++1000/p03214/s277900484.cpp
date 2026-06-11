#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n];
  double ave = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    ave += (double)(a[i]);
  }
  ave /= n;
  int p = 0;
  double mi = abs((double)(a[0]) - ave);
  for(int i = 1; i < n; i++){
    double d = abs((double)(a[i]) - ave);
    if(d < mi){
      p = i;
      mi = d;
    }
  }
  cout << p << endl;
  return 0;
}