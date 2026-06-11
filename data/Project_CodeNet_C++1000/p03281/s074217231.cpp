#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, div=0, count=0; cin >> n;
  for(int i=1;i<=n;i++){
    if(i % 2 == 1){
      for(int j=1;j<=i;j++){if(i % j == 0) div++;} 
      if(div == 8) count++;
      div = 0; 
    }
  }
  cout << count << endl;
  return 0;
}