#include <bits/stdc++.h>
using namespace std;

bool comp(const int& lh, const int& rh) {
    
    if(rh % 10 == 0 || lh % 10 == 0) return lh%10 < rh%10; 
    else return lh%10 > rh%10;
}
 
 
int main(void){
    
  int data[5];
  int ans = 0;
  for(int i=0;i<5;i++) cin >> data[i];
  
  sort(data,data+5,comp);
  
  for(int i=0;i<5;i++) {
      
      ans += data[i];
      
      if(data[i] % 10 != 0 && i!=4){
          ans += (10 - data[i] % 10);
      }
  }
  
  cout << ans << endl;
}