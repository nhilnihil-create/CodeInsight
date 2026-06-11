#include <bits/stdc++.h>
using namespace std;


int main() {
  vector<int> list(3);
  for(int i = 0; i<3; i++){
    cin >> list.at(i); 
  }
  
  sort(list.begin(),list.end());
  
  int answer = list.at(0) + list.at(1) + 10*list.at(2);
  cout << answer << endl;
  
}