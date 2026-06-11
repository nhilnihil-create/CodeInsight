#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,max=1;
  cin >> n;
  vector<int> moti(n);
  for(int i=0;i<n;i++){
    cin >> moti.at(i);
  }
  for(int i=0;i<n-1;i++){
    int memo;
    for(int j=0;j<n-i-1;j++){
      if(moti.at(j)<moti.at(j+1)){
        memo = moti.at(j+1);
        moti.at(j+1) = moti.at(j);
        moti.at(j)=memo;
      }
    }
  }
  int now=moti.at(0);
  for(int i=0;i<n;i++){
    if(now>moti.at(i)){
      max++;
      now=moti.at(i);
    }
  }
  cout << max << endl;
}