#include<bits/stdc++.h>
using namespace std;

int main(){
  
  vector<int> v(6);
  int i, j;
  
  for (i = 0; i < 6; i++){
    cin >> v.at(i);
  }
  
  for (i = 0; i < 5; i++){
    for (j = i + 1; j < 5; j++){
      
      if(abs(v.at(i) - v.at(j)) > v.at(5)){
        cout << ":(" << endl;
        return 0;
      }
    }
  }
  cout << "Yay!" << endl;
  return 0;
}
