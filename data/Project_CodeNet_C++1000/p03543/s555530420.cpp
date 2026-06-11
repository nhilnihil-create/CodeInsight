#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a[4], flag=0;
  cin >> N;
  
  for(int i=0; i<4; i++){
    a[i] = N % 10;
    N /= 10;
    
    if((a[0]==a[1] && a[1]==a[2]) || (a[1]==a[2] && a[2]==a[3]))
      flag=1;
  }
  
  if(flag==1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
  return 0;
}
