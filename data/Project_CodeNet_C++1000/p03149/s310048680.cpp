#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> vec(4);
  for(int i=0; i<4; i++){
    cin >> vec.at(i);
  }
  sort(vec.begin(),vec.end());
  string ans = "YES";
  if(vec.at(0) != 1){
    ans = "NO";
  }
  if(vec.at(1) != 4){
    ans = "NO";
  }
  if(vec.at(2) != 7){
    ans = "NO";
  }
  if(vec.at(3) != 9){
    ans = "NO";
  }
  cout << ans << endl;
}