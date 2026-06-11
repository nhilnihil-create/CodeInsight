#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  char s;
  int flag=0;

  cin >> n;

  for(int i=0;i<n;i++){
    cin >> s;
    if(s == 'Y'){
      cout << "Four" << endl;
      flag=1;
      break;
    }
  }

  if(flag != 1)
    cout << "Three" << endl;
  
    
}