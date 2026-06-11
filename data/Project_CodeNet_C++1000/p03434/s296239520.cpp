#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,Ap=0,Bp=0;
  cin >> n;
  vector<int> point(n);
  for(int i=0;i<n;i++){
    cin >> point.at(i);
  }
  for(int i=0;i<n-1;i++){
    int memo;
    for(int j=0;j<n-i-1;j++){
      if(point.at(j)<point.at(j+1)){
        memo = point.at(j+1);
        point.at(j+1) = point.at(j);
        point.at(j)=memo;
      }
    }
  }
  for(int i=0;i<n;i++){
    if(i%2==0)
      Ap+=point.at(i);
    else
      Bp+=point.at(i);
  }
  cout << Ap-Bp << endl;
}