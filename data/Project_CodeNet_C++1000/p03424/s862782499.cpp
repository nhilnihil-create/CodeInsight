#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<char> vec_n(n);
    
  for(int i= 0; i < n; i++){
    cin >> vec_n.at(i);
  }
  for(int i= 0; i < n; i++){
    if (vec_n.at(i) == 'Y'){
      cout << "Four" << endl;
      break;
    }
    if (i == n-1){
      cout << "Three" << endl;
    }
  }
}
  
  