#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n;
  cin >> n;
  string w[n];
  for(int i = 0; i < n; ++i) cin >> w[i];
  
  for(int i = 0; i < n-1; ++i){
    for(int j = i+1; j < n; ++j){
      if(w[i] == w[j]){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  
  for(int i = 0; i < n-1; ++i){
    if(w[i].back() != w[i+1].front()){
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl;
  return 0;
}