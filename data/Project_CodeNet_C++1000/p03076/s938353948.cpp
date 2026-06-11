#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> time(5);
  for (int i=0 ; i<5 ; i++)
    cin >> time.at(i);
  
  int n;
  vector<int> ten(5);
  for (int i=0 ; i<5 ; i++){
    n = time.at(i)/10;
    n *= 10;
    if (time.at(i)%10 != 0)
      n += 10;
    ten.at(i) = n;
  }
  
  int mini = ten.at(0)-time.at(0), min = 0;
  for (int i=1 ; i<5 ; i++){
    if (ten.at(i)-time.at(i) > mini){
      mini = ten.at(i)-time.at(i);
      min = i;
    }
  }
  
  int ans = 0;
  for (int i=0 ; i<5 ; i++){
    if (i == min){
      ans += time.at(i);
      continue;
    }
    ans += ten.at(i);
  }
  
  cout << ans << endl;
}