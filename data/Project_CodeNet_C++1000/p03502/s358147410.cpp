#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  string ans;
  int value = N;
  int sum = 0;
  while(value!=0){
    sum += value%10;
    value /= 10;
  }
  if(N%sum == 0){
    ans = "Yes";
  }else{
    ans = "No";
  }
  cout << ans << endl;
}