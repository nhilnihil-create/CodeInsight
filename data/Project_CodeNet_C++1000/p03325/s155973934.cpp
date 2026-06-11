#include <bits/stdc++.h>
using namespace std;
int two(int &a){
  int count=0;
  while(a%2 == 0){ 
    a /= 2;
    count++;
  }
  return count;
}
int main(){
  int n;
  cin >> n;
  vector<int> number(n);
  int ans=0;
  for(int i=0; i<n; i++){
    cin >> number.at(i);
    ans += two(number.at(i));
     }
  cout << ans << endl;
}