#include <bits/stdc++.h>
using namespace std;

int main() {
  double n;
  cin >> n;
  vector<int>a(n);
  int sum =0;
  for(int i=0;i<n;i++){
    cin >> a.at(i);
    sum +=a.at(i);
  }
  double ave= (sum/n);
  double dx =1<<30;
  int ans;
  for(int i=0;i<n;i++){
    if( dx > abs(a.at(i) - ave)){
      dx = abs(a.at(i)-ave);
      ans = i;
    }
  }
  cout <<ans;
       
       
}
