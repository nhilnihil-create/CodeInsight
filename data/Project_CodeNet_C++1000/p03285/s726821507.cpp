#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  if (n%4 == 0)
    cout << "Yes" << endl;
  else{
    int m = n/4 + 1;
    int ans = 0;
    for (int i=0 ; i<m ; i++){
      if ((n-4*i)%7 == 0){
        ans = 1;
        break;
      }
    }
    
    if (ans == 1)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}