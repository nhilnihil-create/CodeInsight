#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> a(5);
  
  for(int i = 0; i < 5; i++){
    cin >> a.at(i);
  }
  
  int ans = 0;
  
  for(int i = 0; i < 5; i++){
    if(a.at(i)%10==0){
      ans += a.at(i);
    }
    else{
      ans += (a.at(i)+(10-a.at(i)%10));
    }
  }
  
  vector<int> b = {a.at(0)%10,a.at(1)%10,a.at(2)%10,a.at(3)%10,a.at(4)%10};
  
  sort(b.begin(),b.end());

  int mini = 0;
  
  for(int i = 0; i < 5; i++){
    if(b.at(i)!=0){
      mini = b.at(i);
      break;
    }
  }
  
  if(mini!=0){
    cout << ans - (10-mini) << endl;
  }
  else{
    cout << ans << endl;
  }
  
}