#include<bits/stdc++.h>
using namespace std;
int main() {
  
  vector<int> eachtime(5);
  for(int &c : eachtime) {
    cin >> c;
  }


  int counter = 0, mintime = 643;
  int untilfive = 0;
  
  sort(eachtime.begin(), eachtime.end());
  
  
  
    do{
    
    for(int c : eachtime) {
      counter += c;
      untilfive++;
      
      if(untilfive == 5) {
        break;
      }
      
      if(counter %10 == 0) {
        continue;
      }
      
      else {
        counter += 10 - (counter %10);
      }
    }
      
      
    if(counter < mintime) {
      mintime = counter;
    }
    counter = 0;
    untilfive = 0;
      
  }while(next_permutation(eachtime.begin(), eachtime.end()));
  
  cout << mintime << endl;
}