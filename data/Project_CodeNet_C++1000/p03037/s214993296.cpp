#include <bits/stdc++.h>
using namespace std;

int main(void){
  
  int N,M,l,r,a,b;
  cin >> N >> M;
  for(int i=0;i<M;i++){
      if(i == 0) cin >> l >> r;
      else{
          cin >> a >> b;
          l = max(l,a);
          r = min(r,b);
      }
  }
  if (r-l+1 < 0) cout << 0 << endl;
  else cout << r-l+1 << endl;
}