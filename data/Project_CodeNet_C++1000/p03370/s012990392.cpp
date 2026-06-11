#include <bits/stdc++.h>
using namespace std;

int main(void){
    
  int N,X,m,min=10000,ans=0;
  cin >> N >> X;
  for(int i=0;i<N;i++){
      cin >> m;
      if(m < min) min = m;
      X -= m;
      ans++;
  }
  
  ans += (X/min);
  cout << ans << endl;
}