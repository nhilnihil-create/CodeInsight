#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, a, tmp, cnt, mincnt;
  int i, j;
  
  cin >> n;
  
  for(i = 0; i < n; i++){
    cin >> a;
    tmp = a;
    cnt = 0;
    
    for(j = 0; tmp > 1; j++){
      if((tmp % 2) == 0){
        cnt++;
      }else{
        break;
      }
      tmp /= 2;
    }
    
    if(i == 0) mincnt = cnt;
    if(cnt < mincnt) mincnt = cnt;
  }
  
  cout << mincnt << endl;
}