#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int a,b,k;
  cin >> a >> b >> k;
  
  for(int i=0;i<k&&a<=b;i++){
    cout << a << endl;
    a++;
  }
  for(int i=b-k+1;i<=b;i++){
    if(i>=a) cout << i << endl;
  }
}