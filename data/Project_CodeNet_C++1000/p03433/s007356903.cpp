#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,am;
  cin >> n >> a;
  
  am=n%500;

  if(am <= a){
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  
  return(0);
}
